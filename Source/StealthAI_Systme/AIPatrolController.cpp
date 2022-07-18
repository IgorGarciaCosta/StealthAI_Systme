// Fill out your copyright notice in the Description page of Project Settings.


#include "AIPatrolController.h"
#include "AIPatrolPoint.h"
#include "AIPatrol.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Kismet/GameplayStatics.h"

void AAIPatrolController::OnPossess(APawn* ReceivedPawn)
{
	Super::OnPossess(ReceivedPawn);

	//get ref. to the character
	AAIPatrol* AIChar = Cast<AAIPatrol>(ReceivedPawn);

	if (IsValid(AIChar)) {
		if (AIChar->BehaviorTree->BlackboardAsset) {
			BlackboardComp->InitializeBlackboard(*(AIChar->BehaviorTree->BlackboardAsset));
		}


		//populate patrol point array
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAIPatrolPoint::StaticClass(), PatrolPoints);
		BehaviorComp->StartTree(*AIChar->BehaviorTree);
		
	}
}

AAIPatrolController::AAIPatrolController()
{
	
	//initialize blackvoard comp and behavior tree
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>("BehaviorComp");
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>("BlackboardComp");

	//initialize blackboard keys
	PlayerKey = "Target";
	LocationToGoKey = "LocationToGo";
	CurrentPatrolPoint = 0;

}

void AAIPatrolController::SetPlayerCaught(APawn* CaughtPawn)
{
	if (BlackboardComp) {
		BlackboardComp->SetValueAsObject(PlayerKey, CaughtPawn);
	}
}
