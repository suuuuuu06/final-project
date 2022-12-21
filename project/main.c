//
//  main.c
//  infestPath
//
//  Created by Juyeop Kim on 2022/10/20.
//

#include <stdio.h>
#include <string.h>
#include "ifct_element.h"
#include "ifct_database.h"
#define MENU_PATIENT        1
#define MENU_PLACE          2
#define MENU_AGE            3
#define MENU_TRACK          4
#define MENU_EXIT           0

#define TIME_HIDE           2
void* ifctele_genElement(int index, int age, unsigned int detected_time, int history_place[N_HISTORY]);
char* ifctele_getPlaceName(int placeIndex);
int ifctele_getHistPlaceIndex(void* obj, int index);
unsigned int ifctele_getinfestedTime(void* obj);
int ifctele_getAge(void* obj);
void ifctele_printElement(void* obj);


void ifctele_printElement(void* obj);
int trackInfester(int patient_no, int *detected_time, int *place);
int main(int argc, const char * argv[]) {
    
    int menu_selection;
    void *ifct_element;
    FILE* fp;
    int pindex, age, time;
    int placeHist[N_HISTORY];
    
    
    
    //------------- 1. loading patient info file ------------------------------
    //1-1. FILE pointer open
    if (argc != 2)
    {
        printf("[ERROR] syntax : infestPath (file path).");
        return -1;
    }
    
    fp = fopen(argv[1],"r");
    if (fp == NULL)
    {
        printf("[ERROR] Failed to open database file!! (%s)\n", argv[1]);
        return -1;
    }
    
    
    fp=fopen("patientInfo_prb1.txt","r");
    
    //1-2. loading each patient informations

    while(fscanf(fp,"%d" "%d" "%d",&pindex,&age,&time)==3)
	{
    	
    	int i;
    	for(i=0;i<N_HISTORY;i++)
    	{
			fscanf(fp,"%d",&placeHist[i]);
    	}
    	
    	ifct_element=ifctele_genElement(pindex,age,time,placeHist);
    	ifctdb_addTail(ifct_element);
	}
	
	//ifctdb_len();
	

    
    //1-3. FILE pointer close
    fclose(fp);
    
    do {
        printf("\n=============== INFECTION PATH MANAGEMENT PROGRAM (No. of patients : %i) =============\n", ifctdb_len());
        printf("1. Print details about a patient.\n");                      //MENU_PATIENT
        printf("2. Print list of patients infected at a place.\n");        //MENU_PLACE
        printf("3. Print list of patients in a range of age.\n");          //MENU_AGE
        printf("4. Track the root of the infection\n");                     //MENU_TRACK
        printf("0. Exit.\n");                                               //MENU_EXIT
        printf("=============== ------------------------------------------------------- =============\n\n");
        
        printf("Select a menu :");
        scanf("%d", &menu_selection);
        fflush(stdin);
        
        switch(menu_selection)
        {
            case MENU_EXIT:
                printf("Exiting the program... Bye bye.\n");
                break;
            
			// 1. 특정 index값 환자에 대한 정보 출력     
            case MENU_PATIENT:
            {
					
            	printf("환자의 번호를 입력하세요: ");
            	scanf("%d",&pindex);
            	int i;
	            for(i=0;i<ifctdb_len();i ++) //i번쨰 감염정보 구조체를 liked list로 꺼냄
					{
						ifct_element=ifctdb_getData(i); //getdata 함수로 void 포인터 구조체를 반환 받음
						
					
						if (i==pindex) //입력한 값의 환자 정보 출력
						   ifctele_printElement(ifct_element);
							
					} 
				
				
                break;
            }
           
			// 2. 특정 장소에서 감염이 확인된 환자 관련 정보 출력     
            case MENU_PLACE:
            {    //지정된 장소(문자열 형태로 입력)에서 발병 확인 된 환자 모두의 정보출력
				// enum 문자를 정수로 바꾸는 거 필요
				/*char city;
				printf("장소를 입력하시오: ");
				scanf("%s",&city);
				enum place city= int num;
				
				// int place_num 
				//for(i=0;i<ifctdb_len();i++)
				//{
				ifct_element=ifctdb_getData(1);
				int num2= ifctele_getHistPlaceIndex(ifct_element,i);
	
					if (num==num2[5])
					{
						ifctele_printElement(ifct_element);
					}
				}*/
				//enum place jeju= int i;
				//printf("%d",i);
                break;
            	
        	}
        	
        	
			// 3. 특정 나이 범위 환자 정보 출력   
            case MENU_AGE:
            {
				int i;	
                int age_min;
				int age_max;
				
				printf("나이를 입력하세요: ");
				scanf("%d,%d",&age_min,&age_max);
				
				for(i=0;i<ifctdb_len();i++)
				{
					ifct_element=ifctdb_getData(i);
					int age=ifctele_getAge(ifct_element);
						
					if (age>=age_min&&age<=age_max)  //입력값 조건 만족시키는 환자 정보 출력  
					{
						ifctele_printElement(ifct_element);
						printf("\n");
					}
					 
				}
                break;
        	}
        	
            case MENU_TRACK:
                    
                break;
                
            default:
                printf("[ERROR Wrong menu selection! (%i), please choose between 0 ~ 4\n", menu_selection);
                break;
        }
    
    } while(menu_selection != 0);
    
    //free(struct ifs_ele*ptr);
    return 0;
}
