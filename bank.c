#include <stdio.h>

char names[100][50];
int acc_no[100];
float balance[100];
int total_accounts = 0;

void create_account();
void deposit_money();
void withdraw_money();
void check_balance();

int main()
{
    int choice;

    do
    {
        printf("\n--- BANK MANAGEMENT SYSTEM ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create_account();
                break;
            case 2:
                deposit_money();
                break;
            case 3:
                withdraw_money();
                break;
            case 4:
                check_balance();
                break;
            case 5:
                printf("Thank You!\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while(choice != 5);

    return 0;
}

void create_account()
{
    printf("Enter Name: ");
    scanf("%s", names[total_accounts]);

    printf("Enter Account Number: ");
    scanf("%d", &acc_no[total_accounts]);

    balance[total_accounts] = 0;

    total_accounts++;

    printf("Account Created Successfully!\n");
}

void deposit_money()
{
    int account, i;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &account);

    printf("Enter Amount: ");
    scanf("%f", &amount);

    for(i = 0; i < total_accounts; i++)
    {
        if(acc_no[i] == account)
        {
            balance[i] += amount;
            printf("Deposit Successful!\n");
            return;
        }
    }

    printf("Account Not Found!\n");
}

void withdraw_money()
{
    int account, i;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &account);

    printf("Enter Amount: ");
    scanf("%f", &amount);

    for(i = 0; i < total_accounts; i++)
    {
        if(acc_no[i] == account)
        {
            if(balance[i] >= amount)
            {
                balance[i] -= amount;
                printf("Withdrawal Successful!\n");
            }
            else
            {
                printf("Insufficient Balance!\n");
            }
            return;
        }
    }

    printf("Account Not Found!\n");
}

void check_balance()
{
    int account, i;

    printf("Enter Account Number: ");
    scanf("%d", &account);

    for(i = 0; i < total_accounts; i++)
    {
        if(acc_no[i] == account)
        {
            printf("Name: %s\n", names[i]);
            printf("Balance: Rs %.2f\n", balance[i]);
            return;
        }
    }

    printf("Account Not Found!\n");
}