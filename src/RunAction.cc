#include "RunAction.hh"
#include "PrimaryGeneratorAction.hh"
#include "globals.hh"

RunAction::RunAction()
: G4UserRunAction()
{
}

RunAction::~RunAction()
{
  delete G4AnalysisManager::Instance();
}
void RunAction::BeginOfRunAction(const G4Run*)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

	  //analysisManager -> OpenFile("KHALA_Co60");
	  analysisManager -> OpenFile();
	  analysisManager -> CreateNtuple("data", "data");
	  //analysisManager -> SetFirstNtupleId(0);
	  analysisManager -> CreateNtupleIColumn("eventID");
	  analysisManager -> CreateNtupleIColumn("volumeID");
	  analysisManager -> CreateNtupleIColumn("particleID");
	  analysisManager -> CreateNtupleDColumn("edep");
	  //analysisManager -> CreateNtupleIColumn("volumeID_cluster");
	  analysisManager -> CreateNtupleIColumn("trackID");
	  analysisManager -> CreateNtupleIColumn("parentID");
	  analysisManager -> CreateNtupleDColumn("KineticEnergy");
	  analysisManager -> CreateNtupleDColumn("PreKineticEnergy");
	  analysisManager -> FinishNtuple();
	  //analysisManager -> CreateNtupleDColumn("del_time");

	  //analysisManager -> CreateNtupleDColumn("positionX");
	  //analysisManager -> CreateNtupleDColumn("positionY");
	  //analysisManager -> CreateNtupleDColumn("positionZ");
	  //analysisManager -> CreateNtupleDColumn("pre_time");
	  //analysisManager -> CreateNtupleDColumn("post_time");
	  //analysisManager -> CreateNtupleDColumn("process_name");
	  
	  //analysisManager -> CreateNtupleIColumn("time_if");
	  //analysisManager -> OpenFile();
	  //analysisManager -> CreateNtupleIColumn("volumeID");
	  //analysisManager -> CreateNtupleDColumn("edep");
	  //analysisManager -> FinishNtuple();

/*
	  analysisManager -> CreateNtuple("data", "data");
	  analysisManager -> CreateNtupleIColumn("eventID");
	  analysisManager -> CreateNtupleDColumn("edep");
	  analysisManager -> CreateNtupleIColumn("volumeID");
	  analysisManager -> CreateNtupleDColumn("sumedep");
	  analysisManager -> FinishNtuple();
*/
/*
	  analysisManager -> CreateNtuple("event", "energy deposit per event in volume-1");
	  analysisManager -> CreateNtupleDColumn("edep1");
	  analysisManager -> CreateNtupleIColumn("volumeID");
	  //analysisManager -> CreateNtupleIColumn("volumeID");
	  analysisManager -> FinishNtuple();
*/



}


void RunAction::EndOfRunAction(const G4Run*)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager -> Write();
  analysisManager -> CloseFile();
}
