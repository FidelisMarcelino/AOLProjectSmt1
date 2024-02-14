#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define ll long long

struct apartment{
	char location1[31];
	char location2[31];
	ll int price;
	ll int rooms;
	ll int bathrooms;
	ll int carParks;
	char type[30];
	char furnish[15];	
};

void displayFile(apartment data[], int size){
	FILE *fp = fopen("file.csv", "r");
	
	if(fp == NULL) {
		printf("Data tidak ditemukan!\n");
		return;
	}
	
	char garbage[105];
	
	fscanf(fp, "%[^\n]\n", garbage);
	
	ll int count = 0;
	while(!feof(fp)) {
		fscanf(fp, "%[^,],%[^,],%lld,%lld,%lld,%lld,%[^,],%s\n", data[count].location1, data[count].location2, &data[count].price, &data[count].rooms, &data[count].bathrooms, &data[count].carParks, data[count].type, data[count].furnish);
		count++;
	}
	
	printf("===========================================================================================================================\n");
	printf("| Location	      	    | City	       | Price      | Rooms | Bathrooms | Car Parks | Type 	 | Furnish        |\n");
	printf("===========================================================================================================================\n");
	for(ll i = 0; i < size; i++) {
		printf("| %-25s | %-16s | %-10lld | %-5lld | %-9lld | %-9lld | %-10s | %-15s|\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carParks, data[i].type, data[i].furnish);
	}
	printf("===========================================================================================================================\n");
	
	fclose(fp);
}

void menuAwal(){
	printf("What do you want to do?\n");
	printf("1. Display Data\n");
	printf("2. Search Data\n");
	printf("3. Sort Data\n");
	printf("4. Export Data\n");
	printf("5. Exit\n");
}

int merge(apartment data[], int left, int right, char *column, char *desc) {
    int mid = (right + left) / 2;
    int curr = 0;
    apartment sortingList[right - left + 1];
    int leftIndex = left;
    int rightIndex = mid + 1;
    
    while (leftIndex <= mid && rightIndex <= right) {
        if (strcmp(column, "Location") == 0 || strcmp(column, "location") == 0) {
            if(strcmp(desc, "asc") == 0){
            	if(strcmp(data[leftIndex].location1, data[rightIndex].location1) < 0) {
            		sortingList[curr++] = data[leftIndex++];
				} else {
					sortingList[curr++] = data[rightIndex++];
				}
			} else if(strcmp(desc, "des") == 0) {
				if(strcmp(data[leftIndex].location1, data[rightIndex].location1) > 0) {
            		sortingList[curr++] = data[leftIndex++];
				} else {
					sortingList[curr++] = data[rightIndex++];
				}
			}
        } else if(strcmp(column, "City") == 0 || strcmp(column, "city") == 0) {
        	if(strcmp(desc, "asc") == 0){
            	if(strcmp(data[leftIndex].location2, data[rightIndex].location2) < 0) {
            		sortingList[curr++] = data[leftIndex++];
				} else {
					sortingList[curr++] = data[rightIndex++];
				}
			} else if(strcmp(desc, "des") == 0) {
				if(strcmp(data[leftIndex].location2, data[rightIndex].location2) > 0) {
            		sortingList[curr++] = data[leftIndex++];
				} else {
					sortingList[curr++] = data[rightIndex++];
				}
			}
		} else if(strcmp(column, "Price") == 0 || strcmp(column, "price") == 0) {
        	if(strcmp(desc, "asc") == 0){
            	if(data[leftIndex].price < data[rightIndex].price) {
            		sortingList[curr++] = data[leftIndex++];
				} else {
					sortingList[curr++] = data[rightIndex++];
				}
			} else if(strcmp(desc, "des") == 0) {
				if(data[leftIndex].price > data[rightIndex].price) {
            		sortingList[curr++] = data[leftIndex++];
				} else {
					sortingList[curr++] = data[rightIndex++];
				}
			}
		} else if(strcmp(column, "Rooms") == 0 || strcmp(column, "rooms") == 0) {
        	if(strcmp(desc, "asc") == 0){
            	if(data[leftIndex].rooms < data[rightIndex].rooms) {
            		sortingList[curr++] = data[leftIndex++];
				} else {
					sortingList[curr++] = data[rightIndex++];
				}
			} else if(strcmp(desc, "des") == 0) {
				if(data[leftIndex].rooms > data[rightIndex].rooms) {
            		sortingList[curr++] = data[leftIndex++];
				} else {
					sortingList[curr++] = data[rightIndex++];
				}
			}
		} else if(strcmp(column, "Bathroom") == 0 || strcmp(column, "bathroom") == 0) {
        	if(strcmp(desc, "asc") == 0){
            	if(data[leftIndex].bathrooms < data[rightIndex].bathrooms) {
            		sortingList[curr++] = data[leftIndex++];
				} else {
					sortingList[curr++] = data[rightIndex++];
				}
			} else if(strcmp(desc, "des") == 0) {
				if(data[leftIndex].bathrooms > data[rightIndex].bathrooms) {
            		sortingList[curr++] = data[leftIndex++];
				} else {
					sortingList[curr++] = data[rightIndex++];
				}
			}
		} else if(strcmp(column, "Carpark") == 0 || strcmp(column, "carpark") == 0) {
        	if(strcmp(desc, "asc") == 0){
            	if(data[leftIndex].price < data[rightIndex].price) {
            		sortingList[curr++] = data[leftIndex++];
				} else {
					sortingList[curr++] = data[rightIndex++];
				}
			} else if(strcmp(desc, "des") == 0) {
				if(data[leftIndex].price > data[rightIndex].price) {
            		sortingList[curr++] = data[leftIndex++];
				} else {
					sortingList[curr++] = data[rightIndex++];
				}
			}
		} else if(strcmp(column, "Type") == 0 || strcmp(column, "type") == 0) {
        	if(strcmp(desc, "asc") == 0){
            	if(strcmp(data[leftIndex].type, data[rightIndex].type) < 0) {
            		sortingList[curr++] = data[leftIndex++];
				} else {
					sortingList[curr++] = data[rightIndex++];
				}
			} else if(strcmp(desc, "des") == 0) {
				if(strcmp(data[leftIndex].type, data[rightIndex].type) > 0) {
            		sortingList[curr++] = data[leftIndex++];
				} else {
					sortingList[curr++] = data[rightIndex++];
				}
			}
		} else if(strcmp(column, "Furnish") == 0 || strcmp(column, "furnish") == 0) {
        	if(strcmp(desc, "asc") == 0){
            	if(strcmp(data[leftIndex].furnish, data[rightIndex].furnish) < 0) {
            		sortingList[curr++] = data[leftIndex++];
				} else {
					sortingList[curr++] = data[rightIndex++];
				}
			} else if(strcmp(desc, "des") == 0) {
				if(strcmp(data[leftIndex].furnish, data[rightIndex].furnish) > 0) {
            		sortingList[curr++] = data[leftIndex++];
				} else {
					sortingList[curr++] = data[rightIndex++];
				}
			}
		}
    }
    
    while(leftIndex <= mid) {
    	sortingList[curr++] = data[leftIndex++];
	}
	
	while(rightIndex <= right) {
		sortingList[curr++] = data[rightIndex++];
	}
	
	for(int i = 0; i < curr; i++){
		data[left + i] = sortingList[i];
	}
}

void mergeSort(apartment data[], int left, int right, char *column, char *desc){
	if(left < right) {
		int mid = (right + left) / 2;
		mergeSort(data, left, mid, column, desc);
		mergeSort(data, mid + 1, right, column, desc);
		merge(data, left, right, column, desc);
	}
}

void printArray(apartment data[], int size){
	printf("===========================================================================================================================\n");
	printf("| Location	      	    | City	       | Price      | Rooms | Bathrooms | Car Parks | Type 	 | Furnish        |\n");
	printf("===========================================================================================================================\n");
	
	for(ll i = 1; i < size; i++) {
		printf("| %-25s | %-16s | %-10lld | %-5lld | %-9lld | %-9lld | %-10s | %-15s|\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carParks, data[i].type, data[i].furnish);
	}
	
	printf("===========================================================================================================================\n");
}

int linearSearch(struct apartment data[], int size, char *target, char *column) {
    int isFound = 0;

    for (int i = 0; i < size; i++) {
        if (strcmp(column, "Location") == 0 || strcmp(column, "location") == 0) {
            if (strcmp(target, data[i].location1) == 0) {
                // Cetak format jika data ditemukan
                if (!isFound) {
                    printf("===========================================================================================================================\n");
                    printf("| Location	      	    | City	       | Price      | Rooms | Bathrooms | Car Parks | Type 	 | Furnish        |\n");
                    printf("===========================================================================================================================\n");
                }
                printf("| %-25s | %-16s | %-10lld | %-5lld | %-9lld | %-9lld | %-10s | %-15s|\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carParks, data[i].type, data[i].furnish);
                isFound = 1;
            }
        } else if (strcmp(column, "City") == 0 || strcmp(column, "city") == 0) {
            if (strcmp(target, data[i].location2) == 0) {
                // Cetak format jika data ditemukan
                if (!isFound) {
                    printf("===========================================================================================================================\n");
                    printf("| Location	      	    | City	       | Price      | Rooms | Bathrooms | Car Parks | Type 	 | Furnish        |\n");
                    printf("===========================================================================================================================\n");
                }
                printf("| %-25s | %-16s | %-10lld | %-5lld | %-9lld | %-9lld | %-10s | %-15s|\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carParks, data[i].type, data[i].furnish);
                isFound = 1;
            }
        } else if(strcmp(column, "Price") == 0 || strcmp(column, "price") == 0){
        	if(atoll(target) == data[i].price){
        		if(!isFound){
        			printf("===========================================================================================================================\n");
                    printf("| Location	      	    | City	       | Price      | Rooms | Bathrooms | Car Parks | Type 	 | Furnish        |\n");
                    printf("===========================================================================================================================\n");
                }
                printf("| %-25s | %-16s | %-10lld | %-5lld | %-9lld | %-9lld | %-10s | %-15s|\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carParks, data[i].type, data[i].furnish);
                isFound = 1;
			}
		} else if(strcmp(column, "Rooms") == 0 || strcmp(column, "rooms") == 0){
        	if(atoll(target) == data[i].rooms){
        		if(!isFound){
        			printf("===========================================================================================================================\n");
                    printf("| Location	      	    | City	       | Price      | Rooms | Bathrooms | Car Parks | Type 	 | Furnish        |\n");
                    printf("===========================================================================================================================\n");
                }
                printf("| %-25s | %-16s | %-10lld | %-5lld | %-9lld | %-9lld | %-10s | %-15s|\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carParks, data[i].type, data[i].furnish);
                isFound = 1;
			}
		} else if(strcmp(column, "Bathroom") == 0 || strcmp(column, "bathroom") == 0){
        	if(atoll(target) == data[i].bathrooms){
        		if(!isFound){
        			printf("===========================================================================================================================\n");
                    printf("| Location	      	    | City	       | Price      | Rooms | Bathrooms | Car Parks | Type 	 | Furnish        |\n");
                    printf("===========================================================================================================================\n");
                }
                printf("| %-25s | %-16s | %-10lld | %-5lld | %-9lld | %-9lld | %-10s | %-15s|\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carParks, data[i].type, data[i].furnish);
                isFound = 1;
			}
		} else if(strcmp(column, "Carpark") == 0 || strcmp(column, "carpark") == 0){
        	if(atoll(target) == data[i].carParks){
        		if(!isFound){
        			printf("===========================================================================================================================\n");
                    printf("| Location	      	    | City	       | Price      | Rooms | Bathrooms | Car Parks | Type 	 | Furnish        |\n");
                    printf("===========================================================================================================================\n");
                }
                printf("| %-25s | %-16s | %-10lld | %-5lld | %-9lld | %-9lld | %-10s | %-15s|\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carParks, data[i].type, data[i].furnish);
                isFound = 1;
			}
		} else if (strcmp(column, "Type") == 0 || strcmp(column, "type") == 0) {
            if (strcmp(target, data[i].type) == 0) {
                // Cetak format jika data ditemukan
                if (!isFound) {
                    printf("===========================================================================================================================\n");
                    printf("| Location	      	    | City	       | Price      | Rooms | Bathrooms | Car Parks | Type 	 | Furnish        |\n");
                    printf("===========================================================================================================================\n");
                }
                printf("| %-25s | %-16s | %-10lld | %-5lld | %-9lld | %-9lld | %-10s | %-15s|\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carParks, data[i].type, data[i].furnish);
                isFound = 1;
            }
        } else if (strcmp(column, "Furnish") == 0 || strcmp(column, "furnish") == 0) {
            if (strcmp(target, data[i].furnish) == 0) {
                // Cetak format jika data ditemukan
                if (!isFound) {
                    printf("===========================================================================================================================\n");
                    printf("| Location	      	    | City	       | Price      | Rooms | Bathrooms | Car Parks | Type 	 | Furnish        |\n");
                    printf("===========================================================================================================================\n");
                }
                printf("| %-25s | %-16s | %-10lld | %-5lld | %-9lld | %-9lld | %-10s | %-15s|\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carParks, data[i].type, data[i].furnish);
                isFound = 1;
            }
        }
    }

    // Tambahkan format setelah loop selesai
    printf("===========================================================================================================================\n");

    if (!isFound) {
        printf("Data not found!\n");
    }

    return isFound;  // Return isFound value to indicate whether any data is found or not
}

void start() {
    puts("  ___   _____  _      ______ ______  _____    ___  _____  _____  _____ "); sleep(1);
    puts(" / _ \\ |  _  || |     | ___ \\| ___ \\|  _  |  |_  ||  ___|/  __ \\|_   _|"); sleep(1);
    puts("/ /_\\ \\| | | || |     | |_/ /| |_/ /| | | |    | || |__  | /  \\/  | |  "); sleep(1);
    puts("|  _  || | | || |     |  __/ |    / | | | |    | ||  __| | |      | |  "); sleep(1);
    puts("| | | |\\ \\_/ /| |____ | |    | |\\ \\ \\ \\_/  /\\__/ /| |___ | \\__/\\  | |  "); sleep(1);
    puts("\\_| |_/ \\___/ \\_____/ \\_|    \\_| \\_| \\___/ \\____/ \\____/  \\____/  \\_/  "); sleep(1);
	printf("Ready to start? Click Enter!\n");
	getchar();
    system("cls");
}

void end() {
	system("cls");
	sleep(1);
	printf("\n\n\n\n\n\n\n\n\n\n\n"); 
    printf("\t\t\t\to---------------------------------------------o\n"); sleep(1);
    printf("\t\t\t\t|      Thank you for using this program       |\n"); sleep(1);
    printf("\t\t\t\t|           ~~ Fidelis Marcelino~~            |\n"); sleep(1);
    printf("\t\t\t\t|              ~~ 2702312556 ~~               |\n"); sleep(1);
    printf("\t\t\t\to---------------------------------------------o\n"); sleep(0.5);
    printf("\n\n\n\n\n\n\n\n\n\n"); sleep(1);
}

int main()
{
	int size = 3940;
	struct apartment data[4005];
	start();
	FILE *fp = fopen("file.csv", "r");
	
	if(fp == NULL) {
		printf("Data tidak ditemukan!\n");
	}
	
	char garbage[105];
	
	fscanf(fp, "%[^\n]\n", garbage);
	
	ll int count = 0;
	while(!feof(fp)) {
		fscanf(fp, "%[^,],%[^,],%lld,%lld,%lld,%lld,%[^,],%s\n", data[count].location1, data[count].location2, &data[count].price, &data[count].rooms, &data[count].bathrooms, &data[count].carParks, data[count].type, data[count].furnish);
		count++;
	}
	
	point1:
	menuAwal();
	int choiceMenu;
	printf("Your Choice: ");
	scanf("%d", &choiceMenu);
	
	switch(choiceMenu){
		case 1:{
			int rows;
			printf("Number of rows: ");
			scanf("%d", &rows);
			
			displayFile(data, rows);
			sleep(5);
			system("cls");
			goto point1;
			break;
		}
		
		case 2:{
			//searching
			printf("Choose column: ");
			char choiceSearch[20], choiceSearch2[20];
			scanf("%s", choiceSearch);
			printf("What data do you want to find? ");
			scanf("%s", choiceSearch2);
			linearSearch(data, count, choiceSearch2, choiceSearch);
			sleep(5);
			system("cls");
			goto point1;
			break;
		}
			
		case 3:{
			//sorting
			char chooseSort[20], chooseSort2[20];
			printf("Choose column [Use capital letters in front of words!]: ");
			scanf("%s", chooseSort);
			
			point2:
			printf("Sort ascending or descending? [Only asc / des]: ");
			scanf("%s", chooseSort2);
			
			if(strcmp(chooseSort2, "asc") != 0 && strcmp(chooseSort2, "des") != 0) {
				printf("Invalid input. Use 'asc' or 'des' only!\n");
				goto point2;
				break;
			}
			
			printf("Data found. Detail of data:\n");
			mergeSort(data, 0, size-1, chooseSort, chooseSort2);
			printArray(data, 10);
			
			sleep(5);
			system("cls");
			goto point1;
			break;
		}
		
		case 4:{
			char name[10];
			char names[10];
	
			printf("File Name: ");
			scanf("%s", name); getchar();
	
			sprintf(names, "%s.csv", name);
			FILE *outputFile = fopen(names, "w");
	
			if(outputFile == NULL){
				printf("Invalid File Name");
			} else{
				for(int i = 0; i < count; i++){
					fprintf(outputFile, "%s,%s,%lld,%lld,%lld,%lld,%s,%s\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].carParks, data[i].type, data[i].furnish);
				}
				printf("Data succesfully written to file %s.csv\n", name);
			}
			sleep(1);
			system("cls");
			goto point1;
			break;
		}
		
		case 5:{
			end();
			break;
		}
		
		default:{
			system("cls");
			goto point1;
			break;
		}
	}
	
	fclose(fp);
	
	return 0;
}
