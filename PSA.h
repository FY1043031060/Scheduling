//PSA.h
#ifndef PSA_H_
#define PSA_H_

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

//��ҵ�ṹ��
typedef struct PCB
{
    int ID;							//��ʶ��
    int Level;						//���ȼ�
    int ComeTime;					//����ʱ��
    int ServerTime;					//����ʱ��
    int FinishTime;					//���ʱ��
    int TurnoverTime;				//��תʱ��
    double WeightedTurnoverTime;	//��Ȩ��תʱ��
}PCB;


/*
�������ܣ�������ҵ��Ϣ
����˵����
PCBList		std::vector<PCB>&		PCB��
*/
void InputPCB(std::vector<PCB> &PCBList);

/*
�������ܣ�PSA�㷨
����˵����
PCBList		std::vector<PCB>&		PCB��
*/
void PSA(std::vector<PCB> &PCBList);


/*
�������ܣ���ʾ���
����˵����
PCBList		std::vector<PCB>&		PCB��
*/
void show(std::vector<PCB> &PCBList);

/*
�������ܣ��ȽϺ���������sort()����ComeTime��������
����˵����
p1			const PCB&				PCB
p2			const PCB&				PCB
*/
bool CmpByComeTime(const PCB &p1, const PCB &p2);

/*
�������ܣ��ȽϺ���������sort()����Level��������
����˵����
p1			const PCB&				PCB
p2			const PCB&				PCB
*/
bool CmpByLevel(const PCB &p1, const PCB &p2);

#endif
