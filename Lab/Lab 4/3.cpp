#include<stdio.h>
#include<fstream>
#include<time.h>


using namespace std;

class Object
{
public:
    int weight;
    int profit;
    bool isTaken;
    Object()
    {
        weight = 0;
        profit = 0;
        isTaken = false;
    }
};

void getDataFromFile(Object elements[],int Size) ///Read from target file
{
    ifstream myFile1,myFile2;    ///An Object of File Output Stream
    myFile1.open("Weight.txt");
    myFile2.open("Profit.txt");
    int tempW,tempP;
    for(int i=0;i<Size;i++)
    {
            myFile1>>tempW;
            myFile2>>tempP;
            elements[i].weight = tempW;
            elements[i].profit = tempP;
            printf("%d  %d\n",tempW,tempP);
    }
    myFile1.close();
    myFile2.close();
}

int getKnapSackWeight(Object objects[],int Size)
{
    int sum = 0;
    for(int i=0;i<Size;i++)
    {
        sum+=objects[i].weight;
    }
    printf("\nTotal weight Sum : %d\n",sum);
    return (sum*70)/100;
}

int BruteForceApproach(Object objects[],int Size,int knapSackWeight)
{
    bool Checker = true;
    int BruteForceWeight = 0;

    while(Checker)
    {
        Checker = false;
        int tempMax = 0,tempIndex = -1;
        for(int i=0;i<Size;i++)
        {
            if(!objects[i].isTaken && objects[i].weight>tempMax)
            {
                tempMax = objects[i].weight;
                tempIndex = i;
                Checker = true;
            }
        }

        if(objects[tempIndex].weight<=knapSackWeight)
        {
                printf("%d   %d \n",objects[tempIndex].weight,objects[tempIndex].profit);
                BruteForceWeight += objects[tempIndex].weight;
                knapSackWeight -= objects[tempIndex].weight;
        }
        objects[tempIndex].isTaken = true;
    }

    return BruteForceWeight;
}

int main()
{
    int Number_Of_Object;

    printf("Enter how number of Object : ");
    scanf("%d",&Number_Of_Object);
    Object Objects[Number_Of_Object];
    getDataFromFile(Objects,Number_Of_Object);

    int KnapSackWeight = getKnapSackWeight(Objects,Number_Of_Object);
    printf("Knapsack Weight = %d\n\n",KnapSackWeight);

    printf("\n\nBruteForce weight  =  %d \n\n",BruteForceApproach(Objects,Number_Of_Object,KnapSackWeight));

    return 0;
}

