//
//  main.c
//  Cafe
//
//  Created by Muhammad Ashraf on 02/12/2016.
//  Copyright © 2016 Muhammad Ashraf. All rights reserved.
//

#include <stdio.h>

// functions

/* start of functions for cafe KK2 */
void cafeKK2(); // main function for cafe KK2

void ownercafeKK2();
void studentcafeKK2();
void writeFilecafeKK2();
void readFilecafeKK2();
/* end of functions for cafe KK2 */

// global variables
char food[255][255], matricID[10];
int cleanliness, customerfriendly, environment, taste, j, count=0;
float price[255];

int main(int argc, const char * argv[]) {
    
    char user;
    int quit=0;
    
    while (quit!=1) { // loop until quit not equal to 1
        
        // output user list
        printf("\n\n\tCAFE Kolej Kediaman 2 :");
        printf("\n\n\t1. Pemilik Cafe");
        printf("\n\t2. Pelajar");
        printf("\n\te. Exit");
        printf("\n\n\tSiapakah Anda ? : ");
        scanf(" %c", &user); // scan input user
        
        // get user
        switch (user) {
            case '1':
                ownercafeKK2(); // call owner() function
                break;
                
            case '2':
                studentcafeKK2(); // call student() function
                break;
                
            case 'e':
                quit = 1; // quit loop
                break;
                
            default:
                quit = 0; // continue loop
                break;
        }
    }
    return 0;
}

void ownercafeKK2() { // owner of cafe KK2
    
    int action;
    int exitloop=0, i=0, file=0;
    char done;
    
    // output list of action
    printf("\n\n\tCAFE:");
    printf("\n\n\t1. Lihat Senarai Makanan");
    printf("\n\t2. Ubah Senarai Makanan");
    printf("\n\n\tPilihan Anda ? : ");
    scanf("%d", &action); // scan action
    
    // get action
    switch (action) {
        case 1:
            readFilecafeKK2(); // print list of food
            break;
            
        case 2:
            
            while (exitloop!=1) { // loop until user exit
                printf("\n\tNama Makanan : "); // input food
                scanf(" %[^\n]s", food[i]); // scan food
                printf("\n\tHarga Makanan : "); // input price
                scanf(" %f", &price[i]); // scan price
                
                printf("\n\n\tSelesai ? (y/n) : "); // required to exit loop
                scanf(" %c", &done); // scan done
                
                count++;i++;
                
                if (done=='y') { // exit loop if user input 'y'
                    exitloop=1;
                }
            }
            
            writeFilecafeKK2(file);
            
            break;
            
        default:
            break;
    }
}

void studentcafeKK2() { // function student to rate cafe KK2
    
    int action, average, file=1;
    
    // print list of action
    printf("\n\n\tCAFE:");
    printf("\n\n\t1. Lihat Senarai Makanan");
    printf("\n\t2. Rate Cafe");
    printf("\n\n\tPilihan Anda ? : ");
    scanf("%d", &action);
    
    switch (action) {
        case 1:
            readFilecafeKK2(); // print list of food
            break;
            
        case 2:
            
            // input ID and rating for cafe KK2
            printf("\n\n\tSila masukkan ID matrik [tanpa ruang kosong(space)] : ");
            scanf(" %s",matricID); // scan matric id
            printf("\n\n\t(1-Tidak Memuaskan | 5-Memuaskan)");
            printf("\n\n\tSila masukkan rating dari skala 1 - 5 :\n");
            printf("\n\tKebersihan : ");
            scanf(" %d",&cleanliness); // scan rating for cleanliness
            printf("\tMesra Pelanggan : ");
            scanf(" %d",&customerfriendly); // scan rating for customerfriendly
            printf("\tPersekitaran : ");
            scanf(" %d",&environment); // scan rating for environment
            printf("\tKesedapan : ");
            scanf(" %d",&taste); // scan rating for taste
            
            // calculate and print average rate
            average=(cleanliness+customerfriendly+environment+taste)/4;
            printf("\n\tAverage Rating is : %d", average);
            
            writeFilecafeKK2(file); // write rating to file
            break;
            
        default:
            break;
    }
}

void writeFilecafeKK2(int file) { // write/create file
    
    FILE *fp;
    
    if (file==0) { // for owner
        fp = fopen("MenuMakanancafeKK2.txt", "w+"); // open/create file for food's list
        
        // write food into file
        for (j=0; j<count; j++) {
            fprintf(fp, " %s\t%.2f\n", food[j], price[j]);
        }
    } else { // for student
        fp = fopen("RatingcafeKK2.txt", "w+"); // open/create file for rating
        
        // write ID and rating into file
        fprintf(fp, " ID matrik : %s \n", matricID);
        fprintf(fp, "\n Kebersihan : %d", cleanliness);
        fprintf(fp, "\n Mesra Pelanggan :  %d", customerfriendly);
        fprintf(fp, "\n Persekitaran :  %d", environment);
        fprintf(fp, "\n Kesedapan :  %d" ,taste);
    }
    fclose(fp); // close file
}

void readFilecafeKK2() { // read file
    
    char food[255];
    float price;
    
    FILE *fp;
    
    fp = fopen("MenuMakanancafeKK2.txt", "r"); // open file
    
    // output list of food
    printf("\n\tMakanan/Minuman\tHarga(RM)\n\n");
    while ((j = fgetc(fp)) != EOF) {
        fscanf(fp, "%[^\n\t]\t%f", food, &price);
        printf("\t%s\t%.2f\n", food, price );
    }
    fclose(fp); // close file
}
