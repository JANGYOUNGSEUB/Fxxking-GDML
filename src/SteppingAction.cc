#include "SteppingAction.hh"
#include "EventAction.hh"
#include "G4EventManager.hh"



#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4RunManager.hh"
//#include "TString.h"

SteppingAction::SteppingAction()
: G4UserSteppingAction()
{
}

SteppingAction::~SteppingAction()
{
}

void SteppingAction::UserSteppingAction(const G4Step* step)
{
	G4int eventID = G4RunManager::GetRunManager() -> GetCurrentEvent() -> GetEventID();
	G4int particleID = step -> GetTrack() -> GetParticleDefinition() -> GetPDGEncoding();
	G4int volumeID = step -> GetPreStepPoint() -> GetPhysicalVolume() -> GetCopyNo();
	G4String volumeName= step -> GetPreStepPoint() -> GetPhysicalVolume()->GetName(); 
	G4double totalEdep = 1000*(step -> GetTotalEnergyDeposit());
	G4double KineticEnergy = 1000*(step -> GetTrack() -> GetKineticEnergy()); 
	//G4double del_time= step->GetDeltaTime();
	//G4String process_name = step -> GetPostStepPoint() -> GetProcessDefinedStep() -> GetProcessName();

	//G4int volumeID_cluster=0;
	G4int trackID = step -> GetTrack() -> GetTrackID();
	G4int parentID = step -> GetTrack() -> GetParentID();
	G4double PreKineticEnergy = 1000*(step->GetPreStepPoint()->GetKineticEnergy());


	//if(parentID==0)
	{
		 //step->GetPreStepPoint()->SetGlobalTime(0);

	}
	//G4double pre_time = step -> GetPreStepPoint() -> GetGlobalTime();
	//G4double pre_time = step -> GetPreStepPoint() -> GetLocalTime();
	G4double post_time = step -> GetPostStepPoint() -> GetLocalTime();
	//G4cout<<pre_time<<G4endl;
	//G4double positionX = step -> GetTrack() -> GetPosition().getX();
	//G4double positionX = step -> GetPreStepPoint() -> GetPosition().getX();
	//G4double positionY = step -> GetPreStepPoint() -> GetPosition().getY();
	//G4double positionZ = step -> GetPreStepPoint() -> GetPosition().getZ();
	//G4double positionZ = step -> GetTrack() -> GetPosition().getZ();
	G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
//----------------------------------------------6x4cluster-------------------------------------
{
/*
	int arr_vol[6][4]={{201,202,203,204},{205,206,207,208},{209,210,211,212},{213,214,215,216},{217,218,219,220},{221,222,223,224}};
	for(int i=0;i<6;i++)

	{
		for(int j=0;j<4;j++)
		{
			if(volumeID==arr_vol[i][j])
			{
				volumeID_cluster=4000*(i+1);
			}
		}
	}
*/
}

//---------------------------------------------------------------------------------------------
//---------------------------------------------8x3cluster-------------------------------------

	G4int arr_vol[8][3]={{201,202,203},{204,205,206},{207,208,209},{210,211,212},{213,214,215},{216,217,218},{219,220,221},{222,223,224}};

//--------------------------------------------------------------------------------------------
//G4int volumeID;
G4String name;
name="LaBr3_ss_PV";
//if(volumeName==name)
{
//	volumeID=33;
}
//for(int k=0;k<24;k++)
{

//	name = Form("crystal%d_PV",k);

//	if(volumeName==name)
	{
//		volumeID=k+201;

		//for(int i=0;i<8;i++)
		{
			//for(int j=0;j<3;j++)
			{
				//if(volumeID==arr_vol[i][j])
				//if(volumeID>200)
				{
					//volumeID_cluster=1000*(i+1);
					analysisManager -> FillNtupleIColumn(0, eventID);
					analysisManager -> FillNtupleIColumn(1, volumeID);
					analysisManager -> FillNtupleIColumn(2, particleID);
					analysisManager -> FillNtupleDColumn(3, totalEdep);
					//analysisManager -> FillNtupleIColumn(4, volumeID_cluster);
					analysisManager -> FillNtupleIColumn(4, trackID);
					analysisManager -> FillNtupleIColumn(5, parentID);
					//analysisManager -> FillNtupleIColumn(5, time_if);
					analysisManager -> FillNtupleDColumn(6, KineticEnergy);
					analysisManager -> FillNtupleDColumn(7, PreKineticEnergy);
					//analysisManager -> FillNtupleDColumn(6, del_time);
					//analysisManager -> FillNtupleDColumn(8, pre_time);
					//analysisManager -> FillNtupleDColumn(8, post_time);
					//analysisManager -> FillNtupleDColumn(8, positionX);
					//analysisManager -> FillNtupleDColumn(9, positionY);
					//analysisManager -> FillNtupleDColumn(10, positionZ);
					//analysisManager -> FillNtupleSColumn(11, process_name);

					//std::cout<<process_name<<std::endl; 	

					analysisManager -> AddNtupleRow();

					G4double sumedep;
					int vol_inf;

					


						//std::cout<< sumedep<<std::endl;
/*
						analysisManager -> FillNtupleIColumn(0, eventID);
						analysisManager -> FillNtupleDColumn(1, totalEdep);
						analysisManager -> FillNtupleIColumn(2, volumeID);
						analysisManager -> FillNtupleDColumn(3, sumedep);
						analysisManager -> AddNtupleRow();
*/

/*
					G4double Energydep[12];

					EventAction *eventAction = (EventAction *) G4EventManager::GetEventManager() -> GetUserEventAction();
					for(int i=0;i<12;i++)
					{
						if (volumeID == 201+i)
						{
							eventAction -> AddEnergyDeposit1(totalEdep, volumeID);
							//std::cout<< volumeID<<std::endl;
						}

					}
					analysisManager -> AddNtupleRow();
*/
				}

			}
		}


	}
	//else {volumeID=0;}

}



}
