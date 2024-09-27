//Let one hospital is having n number [user input] of cabins which are numbered from 1
//to n serially. Each cabin can accommodate one patient with the condition that odd
//cabin for the male patients and even cabin for the female patients.
//Each cabin has the information as
//a. Cabin Number: (int) [1 to n]
//b. Status: (char) [Y/N] Note: Y-Occupied, N- Not Occupied

//c. Name of Patient: (String)
//d. Gender: (Char- M/F)
//e. Disease: (String)
//Write a program to do the following work in sequence:
//I. Create one linked list of length n irrespective of the admission of the patient.
//II. In a loop take the request of the patient and do the needful as follows.
//i. Admission Request
//a. If the cabin is available [status is N] then allocate the male patient to the
//odd cabin and female patient to the even cabin, and set the cabin detail
//accordingly. [update the node, do not insert]
//b. If the cabin is not available then insert the patient’s request detail
//into the waiting linked list of males or the waiting linked list of females
//[Total 3 linked list: master, waiting_female, waiting_male]
//ii. Discharge Request
//Update the cabin by changing its status and if any waiting patients are there
//then take the patient from the appropriate waiting list and allocate them the
//available cabin (waiting_male →odd cabin or waiting_female→even cabin).
//[Note: Delete from the waiting list and update (not insert) the appropriate
//node of master linked list]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct cabin
{
    int cabin_num;
    char status_855;
    char first_name_855[50];
    char last_name_855[50];
    char disease[50];
    struct cabin *next;
};
struct waiting
{
    char first_name_855[50];
    char last_name_855[50];
    char disease[50];
    struct waiting *next;
};
int n;
int count = 0;

void create_LL(struct cabin **head)
{
    struct cabin *ptr, *new_node;
    while (count < n) // 6
    {
        count++;
        new_node = (struct cabin *)malloc(sizeof(struct cabin));
        new_node->next = NULL;
        new_node->cabin_num = count;
        new_node->status_855 = 'N';
        if (*head == NULL)
        {
            *head = new_node;
            ptr = new_node;
        }
        else
        {
            ptr->next = new_node;
            ptr = ptr->next;
        }
    }
}
void add_waiting(struct waiting **head, struct waiting *temp)
{
    struct waiting *new_node = (struct waiting *)malloc(sizeof(struct waiting));
    strcpy(new_node->first_name_855, temp->first_name_855);
    strcpy(new_node->last_name_855, temp->last_name_855);
    strcpy(new_node->disease, temp->disease);
    new_node->next = NULL;
    struct waiting *ptr = *head;
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}
void admission(struct cabin **head, struct waiting **waiting_male, struct waiting **waiting_female)
{
    int check = 0;
    char first_name_855[50];
    char last_name_855[50];
    char disease[50];
    char gender;
    printf("\nEnter the first name ");
    scanf("%s", first_name_855);
    printf("\nEnter the last name ");
    scanf("%s", last_name_855);
    printf("\nEnter the gender M/F ");
    fflush(stdin);
    scanf("%c", &gender);
    printf("\nEnter the disease ");
    // fflush(stdin);
    scanf("%s", disease);
    struct cabin *ptr = *head;
    if (gender == 'M')
    {
        while (ptr != NULL)
        {
            if (ptr->cabin_num % 2 != 0 && ptr->status_855 == 'N')
            {
                strcpy(ptr->first_name_855, first_name_855);
                strcpy(ptr->last_name_855, last_name_855);
                strcpy(ptr->disease, disease);
                ptr->status_855 = 'Y';
                printf("\nAllocated Cabin No %d", ptr->cabin_num);
                check++;
                break;
            }
            else
            {
                ptr = ptr->next;
            }
        }
    }
    if (gender == 'F')
    {
        while (ptr != NULL)
        {
            if (ptr->cabin_num % 2 == 0 && ptr->status_855 == 'N')
            {
                strcpy(ptr->first_name_855, first_name_855);
                strcpy(ptr->last_name_855, last_name_855);
                strcpy(ptr->disease, disease);
                ptr->status_855 = 'Y';
                printf("\nAllocated Cabin no is :%d ", ptr->cabin_num);
                check++;
                break;
            }
            else
            {
                ptr = ptr->next;
            }
        }
    }
    if (check == 0)
    {
        struct waiting *temp = (struct waiting *)malloc(sizeof(struct waiting));
        strcpy(temp->first_name_855, first_name_855);
        strcpy(temp->last_name_855, last_name_855);
        strcpy(temp->disease, disease);
        if (gender == 'M')
        {
            add_waiting(&(*waiting_male), temp);
            printf("\nPatient added to the waiting list ");
        }
        else
        {
            add_waiting(&(*waiting_female), temp);
            printf("\nPatient added to the waiting list ");
        }
    }
}
void discharge(struct cabin **head, struct waiting **waiting_female, struct waiting **waiting_male)
{
    int num;
    printf("\nEnter the cabin no to be discharged ");
    scanf("%d", &num);
    if (num > n)
    {
        printf("\nInvalid Cabin no ");
        return;
    }
    struct cabin *ptr = *head;
    while (ptr->cabin_num != num && ptr != NULL)
    {
        ptr = ptr->next;
    }
    ptr->status_855 = 'N';
    printf("\nPatient Discharged ");
    if (num % 2 != 0 && *waiting_male != NULL)
    {
        strcpy(ptr->first_name_855, (*waiting_male)->first_name_855);
        strcpy(ptr->last_name_855, (*waiting_male)->last_name_855);
        strcpy(ptr->disease, (*waiting_male)->disease);
        ptr->status_855 = 'Y';
        struct waiting *temp = *waiting_male;
        *waiting_male = (*waiting_male)->next;
        printf("\nMale Waiting List Updated ");
        printf("\nPatient Name : %s %s", temp->first_name_855, temp->last_name_855);
        printf("\nALLOTED CABIN NO. : %d", ptr->cabin_num);
        free(temp);
    }
    if (num % 2 == 0 && *waiting_female != NULL)
    {
        strcpy(ptr->first_name_855, (*waiting_female)->first_name_855);
        strcpy(ptr->last_name_855, (*waiting_female)->last_name_855);
        strcpy(ptr->disease, (*waiting_female)->disease);
        ptr->status_855 = 'Y';
        struct waiting *temp = *waiting_female;
        *waiting_female = (*waiting_female)->next;
        printf("\nFemale Waiting List Updated ");
        printf("\nPatient Name : %s %s", temp->first_name_855, temp->last_name_855);
        printf("\nALLOTED CABIN NO. : %d", ptr->cabin_num);
        free(temp);
    }
}
void display_patient_detail(struct cabin *ptr)
{
    int num;
    printf("\nEnter the cabin number");
    scanf("%d", &num);
    while (ptr->cabin_num != num)
        ;
    {
        ptr = ptr->next;
    }
    printf("\nName : %s %s", ptr->first_name_855, ptr->last_name_855);
    printf("\nCabin no. : %d\t Disease :%s ", ptr->cabin_num, ptr->disease);
}
void display_waiting_list(struct waiting *head)
{
    printf("\n***WAITING LIST*\n");
    struct waiting *ptr = head;
    while (ptr != NULL)
    {
        printf("\nName : %s %s", ptr->first_name_855, ptr->last_name_855);
        printf("\nDisease : %s", ptr->disease);
        ptr = ptr->next;
    }
}
int main()
{
    struct cabin *head = NULL;
    struct waiting *waiting_male = NULL;
    struct waiting *waiting_female = NULL;
    int option;
    printf("Enter the Number of cabins ");
    scanf("%d", &n);
    create_LL(&head);
    do
    {
        printf("\n***Main Menu*");
        printf("\n1.Admission of patient ");
        printf("\n2.Discharge ");
        printf("\n3.View A Patient Detail ");
        printf("\n4.Display Male Waiting List");
        printf("\n5.Display Female Waiting List");
        printf("\n6.EXIT\n");
        printf("Option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            admission(&head, &waiting_male, &waiting_female);
            break;
        case 2:
            discharge(&head, &waiting_female, &waiting_male);
            break;
        case 3:
            display_patient_detail(head);
            break;
        case 4:
            display_waiting_list(waiting_male);
            break;
        case 5:
            display_waiting_list(waiting_female);
            break;
        }
    } while (option != 6);
}
