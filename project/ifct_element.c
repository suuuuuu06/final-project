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
	//��ȣ : ���� 
	int index;
	//���� :����  
	int age;
	//���� ����: ����  
	int time;
	//���� ���� ��� :place_t enum �迭{N_HISTORY}  	
	int place_t[N_HISTORY];


}ifs_ele_t;

/*int funtion{
	ifs_ele_t ifs1;
}*/

//�迭 ��� ���ϰ� linkedlist ��� static ifs_ele_t ifsarray[20]; //����ü �迭 ����. 



char* ifsele_getPlaceName(int placeIndex)
{	
	return countryName[placeIndex];
}


void* ifctele_genElement(int index, int age, unsigned int detected_time, int history_place[N_HISTORY])
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

	//���⿡ free ������ �� �� : element.c���� ����ü ���� main.c�� �ѱ�� �� �׷��� ���⿡ free ������ �ȵ�  
	return ptr;
}



int ifctele_getAge(void* obj)
{
	//����ü���� ���� ���� �������ִ�  �Լ� 
	ifs_ele_t *ptr=(ifs_ele_t *)obj; //
	
	return ptr->age;
}

int ifctele_getHistPlaceIndex(void* obj, int index)
{
	ifs_ele_t *ptr=(ifs_ele_t *)obj;
	
	int i;
	ptr->index;
	for(i=0;i<N_HISTORY;i++)
	{
		(ptr->place_t[i]);
	}
	
	return ptr;
}



unsigned int ifctele_getinfestedTime(void* obj)
{
	ifs_ele_t *ptr=(ifs_ele_t *)obj;
	
	return ptr->time; 
	
}




void ifctele_printElement(void* obj)
{	
	printf("%d\n",ifctdb_len());
	//�Է� ���� ���� ȯ�� ������ ��� 
	 
	ifs_ele_t*ptr=(ifs_ele_t*)obj;

	
	int j;
	printf("index: %d, age: %d, detected time: %d, �̵����: ", ptr->index,ptr->age,ptr-> time);
	for(j=0;j<N_HISTORY;j++)
	{
		int placeindex;
		//(ptr->place_t[j])=placeindex;
			
		printf(" %s",ifsele_getPlaceName((ptr->place_t[j])));
	}
	printf("\n");
		
}
	
	
	/*int i;
	for(i=0;i<ifctdb_len();i ++) //i���� �������� ����ü�� liked list�� ����
	{
		ifct_element=ifctdb_getData(i); //getdata �Լ��� void ������ ����ü�� ��ȯ ����
		ifctele_getAge(ifct_element);
		ifctele_getHistPlaceIndex(ifct_element,i);
		ifctele_getinfestedTime(ifct_element);
		if((strPtr->index)==obj)
		{
			ifctele_printElement(ifct_element);
		}
	
	} 

	
	
	/*int i;
	printf("index: %d, age: %d, detected time: %d ", strPtr->index,strPtr->age,strPtr-> time);
	for(i=0;i<N_HISTORY;i++)
	{
		strPtr->place_t[i];
		printf("�̵����: %s",ifsele_getPlaceName(strPtr->place_t[i]));
	}
	printf("\n"); */
		/*��ȣ ���� �����ð� ��
		for(�̵� ��� ��)
			�̵� ��� ���� ��� ��� */

	// return?
