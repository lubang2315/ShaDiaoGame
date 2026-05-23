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
	
	/*目标ASC*/
	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	/*击飞的敌人*/
	UPROPERTY()
	AActor* TargetActor = nullptr;

	/*是否击飞敌人*/
	UPROPERTY()
	bool bIsHitFly = false;

	/*击飞敌人的起点位置,(技能落点位置)*/
	UPROPERTY()
	FVector HitSourceLocation = FVector::ZeroVector;
	
	/*击飞角度和力度*/
	UPROPERTY()
	FVector HitFlyAngle = FVector::ZeroVector;

	/*攻击技能应用在敌人那个方位*/
	UPROPERTY()
	int32 HitAngle = 0;

	/*攻击敌人的技能规格：普攻，破防，重击*/
	UPROPERTY()
	int32 HitType = 0;
	
};


USTRUCT(BlueprintType)
struct FGEContext_ShaDiaoGame :public FGameplayEffectContext
{
	GENERATED_BODY()

public:

	/*在GE上下文中存储目标ASC，是否击飞，击飞敌人起始位置，击飞角度和力度.技能落点相对于敌人位置，攻击敌人的技能伤害类型*/
	void SetTargetASC(UAbilitySystemComponent* InASC){TargetASC = InASC; };
	void SetTargetActor(AActor* InTargetActor){TargetActor = InTargetActor; };
	void SetTheHitFly(bool InIsHitFly){bIsHitFly = InIsHitFly; };
	void SetTheHitSourceLocation(FVector InHitSourceLocation){HitSourceLocation = InHitSourceLocation; };
	void SetTheHitFlyAngle(FVector InHitFlyAngle){HitFlyAngle = InHitFlyAngle; };
	void SetHitAngle(float InHitAngle){HitAngle = InHitAngle; };
	void SetHitType(float InHitType){HitType = InHitType; };
	
	/*获取目标ASC，是否击飞，击飞敌人起始位置，击飞角度和力度.技能落点相对于敌人位置，攻击敌人的技能伤害类型*/
	UAbilitySystemComponent* GetTargetASC() const {return TargetASC; };
	AActor* GetTargetActor() const {return TargetActor; };
	bool GetIsHitFly() const {return bIsHitFly; };
	FVector GetHitSourceLocation() const {return HitSourceLocation; };
	FVector GetHitFlyAngle() const {return HitFlyAngle; };
	float GetHitAngle() const {return HitAngle; };
	float GetHitType() const {return HitType; };

protected:
	
	/*目标ASC*/
	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	/*击飞的敌人*/
	UPROPERTY()
	AActor* TargetActor = nullptr;
	
	/*是否击飞敌人*/
	UPROPERTY()
	bool bIsHitFly = false;

	/*击飞敌人的起点位置*/
	UPROPERTY()
	FVector HitSourceLocation = FVector::ZeroVector;

	/*击飞角度和力度*/
	UPROPERTY()
	FVector HitFlyAngle = FVector::ZeroVector;
	
	/*攻击技能应用在敌人那个方位*/
	UPROPERTY()
	int32 HitAngle = 0;

	/*攻击敌人的技能规格：普攻，破防，重击*/
	UPROPERTY()
	int32 HitType = 0;
};