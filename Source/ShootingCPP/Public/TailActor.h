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

	// 외형을 만들고 싶다.
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComp;

	// 타겟을 따라다니고 싶다.
	UPROPERTY(EditAnywhere)
	class AActor*	Target;

	// 이동값이 필요하다
	UPROPERTY(EditAnywhere)
	float Speed = 400.0f;	
};
