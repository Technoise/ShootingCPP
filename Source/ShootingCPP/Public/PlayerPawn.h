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
	// ���� / �浹ü�� �����ϰ� �ʹ�.

	// �浹ü ������Ʈ�� �߰��ؼ� Root������Ʈ�� �������ְ� �ʹ�.
	class UBoxComponent* BoxComp;

	// ����(�޽�)������Ʈ�� �߰��ؼ� Root������Ʈ�� ���̰� �ʹ�.
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComp;

	// �߻���ġ�� ȭ��ǥ�� ǥ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* FirePositionComp;

	// ����ִµ��� ���������� �̵���Ű�� �ʹ�.
	// P = P0 + vt
	float Speed = 500.0f;

	// �����¿� �Է��� �޾Ƽ� �̵��ϰ� �ʹ�.
	float h;
	float v;

	void Horzontal(float value);
	void Vertical(float value);

	void ActionFire();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ABullet> BulletFactory;

};
