//PSA.h
#ifndef PSA_H_
#define PSA_H_

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

//作业结构体
typedef struct PCB
{
    int ID;							//标识符
    int Level;						//优先级
    int ComeTime;					//到达时间
    int ServerTime;					//服务时间
    int FinishTime;					//完成时间
    int TurnoverTime;				//周转时间
    double WeightedTurnoverTime;	//带权周转时间
}PCB;


/*
函数功能：输入作业信息
参数说明：
PCBList		std::vector<PCB>&		PCB链
*/
void InputPCB(std::vector<PCB> &PCBList);

/*
函数功能：PSA算法
参数说明：
PCBList		std::vector<PCB>&		PCB链
*/
void PSA(std::vector<PCB> &PCBList);


/*
函数功能：显示结果
参数说明：
PCBList		std::vector<PCB>&		PCB链
*/
void show(std::vector<PCB> &PCBList);

/*
函数功能：比较函数，用于sort()，按ComeTime升序排列
参数说明：
p1			const PCB&				PCB
p2			const PCB&				PCB
*/
bool CmpByComeTime(const PCB &p1, const PCB &p2);

/*
函数功能：比较函数，用于sort()，按Level降序排列
参数说明：
p1			const PCB&				PCB
p2			const PCB&				PCB
*/
bool CmpByLevel(const PCB &p1, const PCB &p2);

#endif
