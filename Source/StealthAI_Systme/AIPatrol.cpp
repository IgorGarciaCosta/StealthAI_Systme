// Fill out your copyright notice in the Description page of Project Settings.


#include "AIPatrol.h"
#include "AIPatrolController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/PawnSensingComponent.h"

// Sets default values
AAIPatrol::AAIPatrol()
{
	//initialize senses
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>("PawnSensingComp");
	PawnSensingComp->SetPeripheralVisionAngle(45.f);
 
}

// Called when the game starts or when spawned
void AAIPatrol::BeginPlay()
{
	Super::BeginPlay();
	if (PawnSensingComp) {
		PawnSensingComp->OnSeePawn.AddDynamic(this, &AAIPatrol::OnPlayerCaught);
	}
	
}



// Called to bind functionality to input
void AAIPatrol::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAIPatrol::OnPlayerCaught(APawn* ReceivedPawn)
{
	//get ref to player controller
	AAIPatrolController* AICont = Cast<AAIPatrolController>(GetController());
	if(AICont) {
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, "Caught");
		AICont->SetPlayerCaught(ReceivedPawn);
	}

}

