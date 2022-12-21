//
//  ifs_element.c
//  InfestPath
//
//  Created by Juyeop Kim on 2020/10/20.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ifct_element.h"

typedef enum place {
    Seoul,          //0
    Jeju,           //1
    Tokyo,          //2
    LosAngeles,     //3
    NewYork,        //4
    Texas,          //5
    Toronto,        //6
    Paris,          //7
    Nice,           //8
    Rome,           //9
    Milan,          //10
    London,         //11
    Manchester,     //12
    Basel,          //13
    Luzern,         //14
    Munich,         //15
    Frankfurt,      //16
    Berlin,         //17
    Barcelona,      //18
    Madrid,         //19
    Amsterdam,      //20
    Stockholm,      //21
    Oslo,           //22
    Hanoi,          //23
    Bangkok,        //24
    KualaLumpur,    //25
    Singapore,      //26
    Sydney,         //27
    SaoPaulo,       //28
    Cairo,          //29
    Beijing,        //30
    Nairobi,        //31
    Cancun,         //32
    BuenosAires,    //33
    Reykjavik,      //34
    Glasgow,        //35
    Warsow,         //36
    Istanbul,       //37
    Dubai,          //38
    CapeTown        //39
} place_t;

char countryName[N_PLACE+1][MAX_PLACENAME] =
{   "Seoul",
    "Jeju",
    "Tokyo",
    "LosAngeles",
    "NewYork",
    "Texas",
    "Toronto",
    "Paris",
    "Nice",
    "Rome",
    "Milan",
    "London",
    "Manchester",
    "Basel",
    "Luzern",
    "Munich",
    "Frankfurt",
    "Berlin",
    "Barcelona",
    "Madrid",
    "Amsterdam",
    "Stockholm",
    "Oslo",
    "Hanoi",
    "Bangkok",
    "KualaLumpur",
    "Singapore",
    "Sydney",
    "SaoPaulo",
    "Cairo",
    "Beijing",
    "Nairobi",
    "Cancun",
    "BuenosAires",
    "Reykjavik",
    "Glasgow",
    "Warsow",
    "Istanbul",
    "Dubai",
    "CapeTown",
    "Unrecognized"
};


typedef struct ifs_ele{
	//번호 : 정수 
	int index;
	//나이 :정수  
	int age;
	//감염 시점: 정수  
	int time;
	//감염 직전 경로 :place_t enum 배열{N_HISTORY}  	
	int place_t[N_HISTORY];


}ifs_ele_t;
 



char* ifsele_getPlaceName(int placeIndex) //정수의 장소를 문자열로 변환시키는 함수  
{	
	return countryName[placeIndex];
}


void* ifctele_genElement(int index, int age, unsigned int detected_time, int history_place[N_HISTORY]) //동적메모리 할당을 이용해 구조체 생성  
{
	ifs_ele_t *ptr;
	
	ptr=(void*)malloc(sizeof(ifs_ele_t));
	
	ptr->index=index;
	ptr->age=age;
	ptr->time=detected_time;
	int i;
	for(i=0;i<N_HISTORY;i++)
	{
		(ptr->place_t[i])=history_place[i];
	}

	//여기에 free 넣으면 안 됨 : element.c에서 구조체 만들어서 main.c에 넘기는 것 그래서 여기에 free 넣으면 안됨  
	return ptr;
}



int ifctele_getAge(void* obj) //구조체에서 나이 값을 추출해주는  함수 
{
	ifs_ele_t *ptr=(ifs_ele_t *)obj; 
	
	return ptr->age;
}

int ifctele_getHistPlaceIndex(void* obj, int index)// 구조체에서 이동 경로를 추출해 주는 함수  
{
	ifs_ele_t *ptr=(ifs_ele_t *)obj;
	
	int i;
	ptr->index;
	for(i=0;i<N_HISTORY;i++)
	{
		(ptr->place_t[i]);
	}
	
	return ptr->place_t[N_HISTORY];
}



unsigned int ifctele_getinfestedTime(void* obj)// 감염 일자를 추출해 주는 함수  
{
	ifs_ele_t *ptr=(ifs_ele_t *)obj;
	
	return ptr->time; 
	
}




void ifctele_printElement(void* obj) //main.c에서 입력 받은 값(조건)의 환자 정보를 출력하는 함수  
{	
	
	 
	ifs_ele_t*ptr=(ifs_ele_t*)obj;
	
	int j;
	printf("환자 번호 : %d, 나이: %d세, 감염확인 일자: %d, 이동경로: ", ptr->index,ptr->age,ptr-> time);
	
	for(j=0;j<N_HISTORY;j++)
	{
		printf(" %s ",ifsele_getPlaceName(ptr->place_t[j]));
	}
	printf("\n");
}
	
	
	
