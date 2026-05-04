//注意此类是我自定义的GECOntext主要目的是利用GE传输一些我们自定义的数据

#pragma once //预处理指令，确保头文件只背包含一次
#include "GameplayEffectTypes.h"
#include "GEContext_ShaDiaoGame.generated.h"


class UGameplayEffect;

USTRUCT(BlueprintType)
struct FGEDamageInfo
{
	GENERATED_BODY()

	/*默认初始值*/
	FGEDamageInfo(){}

	/*发起者ASC*/
	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;
	
	/*目标ASC*/
	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	/*是否击飞敌人*/
	UPROPERTY()
	bool bIsHitFly = false;

	/*击飞力度*/
	UPROPERTY()
	float HitFlyDegree = 0.f;

	/*击飞角度*/
	UPROPERTY()
	FVector HitFlyAngle = FVector::ZeroVector;
	
};


USTRUCT(BlueprintType)
struct FGEContext_ShaDiaoGame :public FGameplayEffectContext
{
	GENERATED_BODY()

public:

	/*在GE上下文中存储目标ASC，是否击飞，击飞力度，击飞角度*/
	void SetSourceASC(UAbilitySystemComponent* InASC){SourceASC = InASC; };
	void SetTargetASC(UAbilitySystemComponent* InASC){TargetASC = InASC; };
	void SetTheHitFly(bool InIsHitFly){bIsHitFly = InIsHitFly; };
	void SetTheHitFlyDegree(float InHitFlyDegree){HitFlyDegree = InHitFlyDegree; };
	void SetTheHitFlyAngle(FVector InHitFlyAngle){HitFlyAngle = InHitFlyAngle; };

	/*获取目标ASC，是否击飞，击飞力度，击飞角度*/
	UAbilitySystemComponent* GetSourceASC() const {return SourceASC; };
	UAbilitySystemComponent* GetTargetASC() const {return TargetASC; };
	bool GetIsHitFly() const {return bIsHitFly; };
	float GetHitFlyDegree() const {return HitFlyDegree; };
	FVector GetHitFlyAngle() const {return HitFlyAngle; };
	

protected:

	/*发起者ASC*/
	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;
	
	/*目标ASC*/
	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	/*是否击飞敌人*/
	UPROPERTY()
	bool bIsHitFly = false;

	/*击飞力度*/
	UPROPERTY()
	float HitFlyDegree = 0.f;

	/*击飞角度*/
	UPROPERTY()
	FVector HitFlyAngle = FVector::ZeroVector;

	
};