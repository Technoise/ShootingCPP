// Fill out your copyright notice in the Description page of Project Settings.


#include "TailActor.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerPawn.h"

// Sets default values
ATailActor::ATailActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// MeshComp를 생성하고
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));

	// 루트컴포넌트로 설정하고 싶다.
	SetRootComponent(MeshComp);
}

// Called when the game starts or when spawned
void ATailActor::BeginPlay()
{
	Super::BeginPlay();

	// 태어날때 목적지를 기억하고 싶다.
	// 만약 Target이 비어있다면 주인공을 찾아서 넣고 싶다.
	if( Target == nullptr || Target->IsValidLowLevel() )
	{
		Target = GetWorld()->GetFirstPlayerController()->GetPawn();
		//Target = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		//Target = UGameplayStatics::GetActorOfClass(GetWorld(), APlayerPawn::StaticClass());
	}
	
}

// Called every frame
void ATailActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 살아가면서 목적지를 향해 이동하고 싶다.
	// P = P0 + vt
	FVector dir = Target->GetActorLocation() - this->GetActorLocation();
	SetActorLocation( GetActorLocation() + dir.GetSafeNormal() * Speed * DeltaTime );

	//float d = Target->GetDistanceTo(this);
	//float dist = FVector::Dist(Target->GetActorLocation(), this->GetActorLocation());
	//float distance = dir.Size();
}

