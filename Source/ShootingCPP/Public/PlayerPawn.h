// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class SHOOTINGCPP_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	// 외형 / 충돌체를 생성하고 싶다.

	// 충돌체 컴포넌트를 추가해서 Root컴포넌트로 설정해주고 싶다.
	class UBoxComponent* BoxComp;

	// 외형(메시)컴포넌트를 추가해서 Root컴포넌트에 붙이고 싶다.
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComp;

	// 발사위치를 화살표로 표시하자
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* FirePositionComp;

	// 살아있는동안 오른쪽으로 이동시키고 싶다.
	// P = P0 + vt
	float Speed = 500.0f;

	// 상하좌우 입력을 받아서 이동하고 싶다.
	float h;
	float v;

	void Horzontal(float value);
	void Vertical(float value);

	void ActionFire();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ABullet> BulletFactory;

};
