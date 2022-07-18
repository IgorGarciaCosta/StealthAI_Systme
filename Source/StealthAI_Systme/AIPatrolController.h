// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AIPatrolController.generated.h"

/**
 * 
 */
UCLASS()
class STEALTHAI_SYSTME_API AAIPatrolController : public AAIController
{

	GENERATED_BODY()

	//behavior tree comp
	UBehaviorTreeComponent* BehaviorComp;

	//blackboard comp
	UBlackboardComponent* BlackboardComp;

	//Blackboard keys
	UPROPERTY(EditDefaultsOnly, Category = AI)
		FName LocationToGoKey;

	UPROPERTY(EditDefaultsOnly, Category = AI)
		FName PlayerKey;

	TArray<AActor*> PatrolPoints;

	virtual void OnPossess(APawn* Pawn) override;

	

public:
	AAIPatrolController();

	void SetPlayerCaught(APawn* Pawn);

	int32 CurrentPatrolPoint = 0;

	//inline getter functions
	FORCEINLINE UBlackboardComponent* GetBlackboardComponent() const { return BlackboardComp; }
	FORCEINLINE TArray<AActor*> GetPatrolPoints() const { return PatrolPoints; }
};
