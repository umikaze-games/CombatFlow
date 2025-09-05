#pragma once

namespace Debug
{
	static void Print(const FString& Msg,const FColor& Color=FColor::MakeRandomColor(),int32 Inkey=-1)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(Inkey,7.f,Color,Msg);
			UE_LOG(LogTemp,Warning,TEXT("%s"),*Msg);
		}
	}
}
