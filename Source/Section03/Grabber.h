// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DrawDebugHelpers.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SECTION03_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float Reach = 100.0f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* Input = nullptr;

	// Ray cast and grab what is in reach.
	void Grab();
	// Called when grab is released.
	void Release();
	// Find attached physics handle.
	void FindPhysicsHandleComponent();

	void FindInputComponent();
	// Return hit for first physics body in reach.
	FHitResult GetFirstPhysicsBodyInReach() const;
	// Returns current start of reach line.
	FVector GetReachLineStart() const;
	// Returns current end of reach line.
	FVector GetReachLineEnd() const;
};
