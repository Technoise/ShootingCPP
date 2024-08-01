// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Components/BoxComponent.h"
#include "Components/ArrowComponent.h"
#include "Bullet.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// �浹ü�� Root
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));

	// Root������Ʈ�� �������ְ� �ʹ�.
	SetRootComponent(BoxComp);

	// ����(�޽�)������Ʈ�� �߰��ؼ� Root������Ʈ�� ���̰� �ʹ�.
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);

	ConstructorHelpers::FObjectFinder<UStaticMesh> TempMesh(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	// �ε尡 ���������� �Ǿ�����
	if( TempMesh.Succeeded() )
	{
		// �޽ÿ� ������ ��������
		MeshComp->SetStaticMesh(TempMesh.Object);
	}

	// �ѱ���ġ�� ȭ��ǥ�� ǥ������
	FirePositionComp = CreateDefaultSubobject<UArrowComponent>(TEXT("FirePositionComp"));
	FirePositionComp->SetupAttachment(RootComponent);
	FirePositionComp->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 100.0f), FRotator(90.0f, 0.0f, 0.0f));		
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ��� ���������� �̵��ϰ� �ʹ�.
	// P = P0 + v( ���� * ũ�� ) t
	//FVector direction = FVector::RightVector;// FVector(0, 1, 0)
	FVector direction = FVector(0, h, v);
	FVector P0 = GetActorLocation();
	FVector vt = direction * Speed * DeltaTime;
	FVector P = P0 + vt;
	
	SetActorLocation(P);
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &APlayerPawn::Horzontal);
	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &APlayerPawn::Vertical);

	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &APlayerPawn::ActionFire);
}

void APlayerPawn::Horzontal(float value)
{
	h = value;
	//UE_LOG(LogTemp, Warning, TEXT("h : %f"), h);
}

void APlayerPawn::Vertical(float value)
{
	v = value;
	//UE_LOG(LogTemp, Warning, TEXT("v : %f"), v);
}

void APlayerPawn::ActionFire()
{
	FTransform t = FirePositionComp->GetComponentTransform();
	GetWorld()->SpawnActor<ABullet>(BulletFactory, t);
}

