/*A program to implement the activity-selection problem stated as follows: You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time. Example: Consider the following 6 activities. start[] = {1, 3, 0, 5, 8, 5}; finish[] = {2, 4, 6, 7, 9, 9}; The maximum set of activities that can be executed by a single person is {0, 1, 3, 4}.*/

#include<stdio.h>

typedef struct Task{
  int id;
  float start_time;
  float end_time;
}Task;

int isGreater(Task obj1, Task obj2)
{
  return obj1.end_time > obj2.end_time;
}

void sort(Task *arr, const int n)
{
    for (int i = 1; i < n; i++)
    {
        Task key = arr[i];
        int j = i - 1;

        while (j >= 0 && isGreater(arr[j], key))
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){
  int n;
  printf("Enter number of Tasks: ");
  scanf("%d",&n);

  Task arr[n];
  printf("Enter Start Time of all tasks: \n");
  for(int i=0;i<n;i++){
    arr[i].id = i;
    scanf("%f",&arr[i].start_time); 
  }

  printf("Enter End Time of all tasks: \n");
  for(int i=0;i<n;i++){
    scanf("%f",&arr[i].end_time);
  }

  sort(arr,n);
  
  printf("\nTaskes taken: %d ",arr[0].id);
  int last_taken = 0;
  for(int i=0;i<n-1;i++){
    if(arr[last_taken].end_time <= arr[i+1].start_time){
      printf("%d ",arr[i+1].id);
      last_taken = i+1;
    }
  }
  return 0;
}
