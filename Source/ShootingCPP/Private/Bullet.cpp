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

	// �ε忡 �����ߴٸ�
	if( TempMesh.Succeeded() )
	{
		// �޽�������Ʈ�� �־�����
		MeshComp->SetStaticMesh(TempMesh.Object);

		// �޽�������Ʈ�� ����� �ٲ�����
		MeshComp->SetRelativeScale3D(FVector(0.75f, 0.25f, 1.0f));

		// �ڽ� ������Ʈ�� ����� �޽� ������Ʈ�� �°� �ٲ�����
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

	// ������ �̵��ϰ� �ʹ�.
	// P = P0 + vt
	FVector dir = GetActorForwardVector();
	FVector P0 = GetActorLocation();
	FVector vt = dir * Speed * DeltaTime;
	FVector P = P0 + vt;
	SetActorLocation(P);
}

