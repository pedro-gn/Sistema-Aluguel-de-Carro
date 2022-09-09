#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 50

typedef struct {
    int id;
    char year[4];
    char plate[MAX_STRING];
    char color[MAX_STRING];
    char model[MAX_STRING];
    char brand[MAX_STRING];
} Car;




void loadCars(FILE *carsFile , Car * cars){
    int carsNumber;
    char c;


    fscanf(carsFile,"%d", &carsNumber); //read registred car number
    cars = (Car * )calloc(carsNumber, sizeof(Car)); //alocate memory for cars with car number
    fscanf(carsFile,"%c", &c); //read \n

    for(int i = 0; i < carsNumber; i++ ){
        
        fscanf(carsFile,"%d %s %s %s %s %s", &cars[i].id, cars[i].brand, cars[i].plate, cars[i].color, cars[i].model, cars[i].year);

        printf("%d \n", cars[i].id);
        printf("%s \n", cars[i].brand);
        printf("%s \n", cars[i].color);
        printf("%s \n", cars[i].model);
        printf("%s \n", cars[i].plate);
        printf("%s \n", cars[i].year);
                

    }

}




int main(){
    FILE *carsFile;
    carsFile = fopen("cars.txt", "r");
    Car *cars;


    loadCars(carsFile, cars);



    fclose(carsFile);
}