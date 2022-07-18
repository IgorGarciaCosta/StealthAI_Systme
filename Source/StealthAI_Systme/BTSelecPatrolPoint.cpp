// Fill out your copyright notice in the Description page of Project Settings.


#include "BTSelecPatrolPoint.h"
#include "AIPatrolPoint.h"
#include "AIPatrolController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTSelecPatrolPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIPatrolController* AICon = Cast<AAIPatrolController>(OwnerComp.GetOwner());

	if (AICon) {
		//get bb component
		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComponent();

		AAIPatrolPoint* CurrentPoint = Cast< AAIPatrolPoint>(BlackboardComp->GetValueAsObject("LocationToGo"));

		TArray<AActor*> AvailablePatrolPoints = AICon->GetPatrolPoints();

		AAIPatrolPoint* NxtPatrolPoint = nullptr;

		if (AICon->CurrentPatrolPoint != AvailablePatrolPoints.Num()-1) {
			NxtPatrolPoint = Cast< AAIPatrolPoint>(AvailablePatrolPoints[++AICon->CurrentPatrolPoint]);
		}
		else {//no more points to go to
			NxtPatrolPoint = Cast< AAIPatrolPoint>(AvailablePatrolPoints[0]);
			AICon->CurrentPatrolPoint = 0;
		}
		BlackboardComp->SetValueAsObject("LocationToGo", NxtPatrolPoint);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
