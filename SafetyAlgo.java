import java.util.Scanner;

public class SafetyAlgo
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Input number of processes: ");
        int p = sc.nextInt();
        System.out.println("Input number of resource type: ");
        int r = sc.nextInt();
        int Avaliable[] = new int[r]; 
        int Allocation[][] = new int[p][r];
        int Max[][] = new int[p][r];
        int Need[][] = new int[p][r];
        boolean Finish[] = new boolean[p];
        int result[] = new int[p];
        //Assigning all the values of finish to false
        for(int i=0; i<p; i++)
            Finish[i] = false;
        System.out.println("Enter the resorces avaliable: ");
        for(int i = 0; i<r; i++)
            Avaliable[i] = sc.nextInt();
        for(int i=0; i<p; i++)
        {
            System.out.println("Enter the allocated resources for process: "+i);
            for(int j=0; j<r; j++)
            {
                Allocation[i][j] = sc.nextInt();
            }
        }
        //Taking the sum of allocates resources
        int sum[] = new int[r];
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<p; j++)
            {
                sum[i] = Allocation[j][i];
            }
        }
        //Adding allocated and avaliable resources
        for(int i=0; i<r; i++)
        {
            sum[i] = sum[i]+Avaliable[i];
        }
        //Inputing maximum number of resources of each type required by each process
        int in =0;
        for(int i=0; i<p; i++)
        {
            System.out.println("Enter the maximum resources required for process: "+i);
            while(in != 1)
            {
                for(int j=0; j<r; j++)
                {
                    Max[i][j] = sc.nextInt();
                }
                for(int k=0; k<r; k++)
                {
                    if(Max[i][k]>sum[k])
                    {
                        System.out.println("Values entered are wrong, please re-enter values for process "+i);
                        in = 0;
                        break;
                    }
                    in = 1;
                }
            }
        }

        //Calculate the need of resources for each process
        for(int i = 0; i<p; i++)
        {
            for(int j=0; j<r; j++)
            {
                Need[i][j] = Max[i][j] - Allocation[i][j];
            }
        }

        //creating a new array work to store the value of avaliable resouces and work on it without manipulating avaliable
        int work[] = new int[r];
        for(int i=0; i<r; i++)
            work[i] = Avaliable[i];
        
        int ch = 0, t=0, d=0, a=0;
        while(t!=1)
        {
            ch = 0;
            for(int i=0; i<p; i++)
            {
                for(int j=0; j<r; j++)
                {
                    if(Need[i][j] <= work[j])
                        ch = 1;
                    else
                        ch = 0;
                }
                if(Finish[i]==false && ch==1)
                {
                    for(int j=0; j<r; j++)
                    {
                        work[j] = work[j] + Allocation[i][j];
                    }
                    result[d] = i;
                    d++;
                    Finish[i] = true;
                }
            }
            a=0;
            for(int i=0; i<p; i++)
            {
                if(Finish[i] == true)
                    a++;
            }
            if(a==p)
                t=1;
            else
                t=0;
        }
        
    }
}