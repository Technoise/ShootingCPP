// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TailActor.generated.h"

UCLASS()
class SHOOTINGCPP_API ATailActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATailActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// ������ ����� �ʹ�.
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComp;

	// Ÿ���� ����ٴϰ� �ʹ�.
	UPROPERTY(EditAnywhere)
	class AActor*	Target;

	// �̵����� �ʿ��ϴ�
	UPROPERTY(EditAnywhere)
	float Speed = 400.0f;	
};
