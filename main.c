#include <stdio.h>
#include <stdlib.h>

enum {leer = 0, gefahren, brunnen, relikt};

struct robot {
    int position[2];// 1 is x, 0 is y
    int live;
    int point;
} typedef robot;

struct enemy{
    int position[2];
}typedef enemy;

// for level 3 , using linked list to print step ....
//struct node {
//    int yPositionRobot;
//    int xPositionRobot;
//    int RobotLive;
//    int RobotPoint;
//    int yPositionEnemy;
//    int xPositionEnemy;
//    struct node* next;
//};
//
//struct node* create(int yPositionRobot, int xPositionRobot, int RobotLive, int RobotPoint, int yPositionEnemy, int xPositionEnemy){
//    struct node* newNode = (struct node*) malloc(sizeof ( struct node));
//    newNode->yPositionRobot = yPositionRobot;
//    newNode->xPositionRobot = xPositionRobot;
//    newNode->RobotLive = RobotLive;
//    newNode->RobotPoint = RobotPoint;
//    newNode->yPositionEnemy = yPositionEnemy;
//    newNode->xPositionEnemy = xPositionEnemy;
//
//    return newNode;
//}
//
//struct node* addFirst(struct node* head, int yPositionRobot, int xPositionRobot, int RobotLive, int RobotPoint, int yPositionEnemy, int xPositionEnemy){
//    struct node* newHead = create(yPositionRobot, xPositionRobot, RobotLive, RobotPoint, yPositionEnemy, xPositionEnemy);
//    newHead->next = head;
//    return newHead;
//}
//
//struct node* addLast(struct node* head, int yPositionRobot, int xPositionRobot, int RobotLive, int RobotPoint, int yPositionEnemy, int xPositionEnemy){
//    struct node* temp = head;
//    while(temp->next != NULL){
//        temp = temp->next;
//    }
//    struct node* newNode = create(yPositionRobot, xPositionRobot, RobotLive, RobotPoint, yPositionEnemy, xPositionEnemy);
//    newNode->next = NULL;
//    temp->next = newNode;
//    return head;
//}
//struct node* add(struct node* head, int yPositionRobot, int xPositionRobot, int RobotLive, int RobotPoint, int yPositionEnemy, int xPositionEnemy){
//    if(head == NULL){
//        return addFirst(head, yPositionRobot, xPositionRobot, RobotLive, RobotPoint, yPositionEnemy, xPositionEnemy);
//    }
//    struct node* temp = head;
//    while(temp->next != NULL){
//        temp = temp->next;
//    }
//    return addLast(head, yPositionRobot, xPositionRobot, RobotLive, RobotPoint, yPositionEnemy, xPositionEnemy);
//}
//
//void printList(struct node* head){
//    int step = 0;
//    while(head != NULL){
//        printf("\nStep: %d", step);
//        printf("\nPosition of Robot (%d:%d) with %d Lives and %d Point", head->yPositionRobot, head->xPositionRobot, head->RobotLive, head->RobotPoint);
//        if(head->yPositionEnemy > 0 && head->xPositionEnemy > 0){
//            printf("\nPosition of Enemy (%d:%d)", head->yPositionEnemy, head->xPositionEnemy);
//        }
//
//        if(head->next != NULL){
//            printf("\n👇👇👇👇");
//        }
//        step++;
//        head = head->next;
//
//    }
//}
//
//struct node* removeFirst(struct node* head)
//{
//    if(head == NULL)
//        return head;
//
//    struct node* newHead = head->next;
//    free(head);
//    return newHead;
//}
//
//struct node* removeAll(struct node* head)
//{
//    struct node* temp = head;
//    while(temp != NULL)
//    {
//        temp = removeFirst(temp);
//    }
//    return temp;
//}

int countPoint(int array[5][5]){

    int sum = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(array[i][j] == relikt){
                sum++;
            }
        }
    }
    return sum;
}
//Felder
int c;// all the point (relikt) in  game

void generateFelder(int array[5][5], int yPosition, int xPosition){
    int zufall;// for random function
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            // i == robot 1 und robot 2
            zufall = rand()%100;
            if(zufall <= 40) {
                array[i][j] = leer;
            }else if(zufall <= 80 ){
                array[i][j] = gefahren;
            }
            else if(zufall <= 90 ){
                array[i][j] = brunnen;
            }else{
                array[i][j] = relikt;
            }

        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(i == yPosition && j == xPosition){
                printf("🤖 ");
            }
            else if(array[i][j] == leer){
                printf("☘️ ");
            }
            else if(array[i][j] == gefahren){
                printf("❗️ ");
            }else if(array[i][j] == brunnen){
                printf("🧚 ");
            }else if(array[i][j] == relikt){
                printf("👑 ");
            }

        }
        printf("\n");
    }
    c = countPoint(array);

}

//Movement
int checkOkToMove(int yPosition, int xPosition){
    if(xPosition < 0 || xPosition > 4){
        return 0;
    }else if(yPosition < 0 || yPosition > 4){
        return 0;
    }else{
        return 1;
    }
}
//function to control the dummy enemy


//Print map
void printMap(int array[5][5], int yPosition, int xPosition, int yEnemyPosition, int xEnemyPosition){

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(i == yPosition && j == xPosition){
                array[i][j] = '@';
            }

            //to set the previous position to leer
            if(array[i][j] == '@'){
                if(i != yPosition || j != xPosition ){
                    array[i][j] = leer;
                }
            }
            if(i == yPosition && j == xPosition){
                printf("🤖 ");
            } else if(i == yEnemyPosition && j == xEnemyPosition){
                printf("🤡 ");
            }
            else if(array[i][j] == leer){
                printf("☘️ ");
            }
            else if(array[i][j] == gefahren){
                printf("❗️ ");
            }else if(array[i][j] == brunnen){
                printf("🧚 ");
            }else if(array[i][j] == relikt){
                printf("👑 ");
            }
        }
        printf("\n");
    }
}

//function to count point and live
void countPointAndLife(int array[5][5], int yPosition, int xPosition, robot* Robot, enemy* Enemy){
    if(array[yPosition][xPosition] == gefahren){
        //1/6 lose the point
        int zufall = rand()%60;
        if(zufall <= 30&& zufall >= 20){
            Robot->live--;
        }
    }else if(array[Robot->position[0]][Robot->position[1]] == brunnen){
        Robot->live++;
    }
    else if(array[Robot->position[0]][Robot->position[1]] == relikt){
        Robot->point++;
    }
    printMap(array, Robot->position[0], Robot->position[1], Enemy->position[0], Enemy->position[1]);

}

// function to count point (relikt)


//printStat
void printStat(int live, int point){
    printf("\nYour live: %d", live);
    printf("\nYour point: %d", point);
}


int main() {

    // for Robot (as the Player)
    robot Robot;
    Robot.live = 5;
    Robot.point = 0;

    // for enemy
    enemy DummyEnemy;
    DummyEnemy.position[0] = 0;
    DummyEnemy.position[1] = - 1;

    // What we need
    int array[5][5];

    char a; // w, a, s or d
    struct node* head = NULL;

    // felder generate
    printf("\n****** WELCOME PLAYER TO GAME ******\n");
    printf("\n");
    while(1){
        Robot.position[0] = 0;
        Robot.position[1] = 0;
        printf("---------------\n");
        generateFelder(array, Robot.position[0], Robot.position[1]);

        // in game
        do{
            printStat(Robot.live, Robot.point);
            printf("\nWohin willst du gehen: ");
            printf("\n");
            scanf(" %c", &a);

            switch(a){
                case 'w':
                    Robot.position[0]--;
                    DummyEnemy.position[0]--;
                    if(!checkOkToMove(Robot.position[0], Robot.position[1])){
                        printf("\nInvalid move");
                        Robot.position[0]++;
                        DummyEnemy.position[0]++;
                    }else{
                        //check lives and points
                        countPointAndLife(array, Robot.position[0], Robot.position[1], &Robot, &DummyEnemy);
                    }

                    break;
                case 's':
                    Robot.position[0]++;
                    DummyEnemy.position[0]++;
                    if(!checkOkToMove(Robot.position[0], Robot.position[1])){
                        printf("\nInvalid move");
                        Robot.position[0]--;
                        DummyEnemy.position[0]--;
                    }else{
                        countPointAndLife(array, Robot.position[0], Robot.position[1], &Robot, &DummyEnemy);

                    }
                    break;
                case 'd':
                    Robot.position[1]++;
                    DummyEnemy.position[1]++;
                    if(!checkOkToMove(Robot.position[0], Robot.position[1])){
                        printf("\nInvalid move");
                        Robot.position[1]--;
                        DummyEnemy.position[1]--;
                    }else{
                        countPointAndLife(array, Robot.position[0], Robot.position[1], &Robot, &DummyEnemy);

                    }
                    break;
                case 'a':
                    Robot.position[1]--;
                    DummyEnemy.position[1]--;
                    if(!checkOkToMove(Robot.position[0], Robot.position[1])){
                        printf("\nInvalid move");
                        Robot.position[1]++;
                        DummyEnemy.position[1]++;
                    }else{
                        countPointAndLife(array, Robot.position[0], Robot.position[1], &Robot, &DummyEnemy);

                    }
                    break;
            }

//        head = add(head, Robot.position[0], Robot.position[1], Robot.live, Robot.point, DummyEnemy.position[0], DummyEnemy.position[1]);

            // if player took all the point, we would end the game
            if(Robot.point == c){
                break;
            }


        }while(Robot.live > 0 || Robot.point == c);
    }





    if(Robot.live < 0){
        printf("\nTry it next time. You are dead");
    } else if(Robot.point == c){
        printf("\nCONGRATULATIONS. You did it");
    }
//    printList(head);
//    removeAll(head);

    return 0;
}
