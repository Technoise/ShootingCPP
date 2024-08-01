// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Components/BoxComponent.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	SetRootComponent(BoxComp);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);

	ConstructorHelpers::FObjectFinder<UStaticMesh> TempMesh(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	// 로드에 성공했다면
	if( TempMesh.Succeeded() )
	{
		// 메시컴포넌트에 넣어주자
		MeshComp->SetStaticMesh(TempMesh.Object);

		// 메시컴포넌트의 사이즈를 바꿔주자
		MeshComp->SetRelativeScale3D(FVector(0.75f, 0.25f, 1.0f));

		// 박스 컴포넌트의 사이즈도 메시 컴포넌트에 맞게 바꿔주자
		BoxComp->SetBoxExtent(FVector(37.5f, 12.5f, 50.0f));
	}
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 앞으로 이동하고 싶다.
	// P = P0 + vt
	FVector dir = GetActorForwardVector();
	FVector P0 = GetActorLocation();
	FVector vt = dir * Speed * DeltaTime;
	FVector P = P0 + vt;
	SetActorLocation(P);
}

