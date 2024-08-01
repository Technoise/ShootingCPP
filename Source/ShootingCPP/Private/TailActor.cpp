// Fill out your copyright notice in the Description page of Project Settings.


#include "TailActor.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerPawn.h"

// Sets default values
ATailActor::ATailActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// MeshComp�� �����ϰ�
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));

	// ��Ʈ������Ʈ�� �����ϰ� �ʹ�.
	SetRootComponent(MeshComp);
}

// Called when the game starts or when spawned
void ATailActor::BeginPlay()
{
	Super::BeginPlay();

	// �¾�� �������� ����ϰ� �ʹ�.
	// ���� Target�� ����ִٸ� ���ΰ��� ã�Ƽ� �ְ� �ʹ�.
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

	// ��ư��鼭 �������� ���� �̵��ϰ� �ʹ�.
	// P = P0 + vt
	FVector dir = Target->GetActorLocation() - this->GetActorLocation();
	SetActorLocation( GetActorLocation() + dir.GetSafeNormal() * Speed * DeltaTime );

	//float d = Target->GetDistanceTo(this);
	//float dist = FVector::Dist(Target->GetActorLocation(), this->GetActorLocation());
	//float distance = dir.Size();
}

