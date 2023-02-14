//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file PrimaryGeneratorAction.cc
/// \brief Implementation of the PrimaryGeneratorAction class
//
// $Id$
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
#include "PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleTable.hh"
#include "G4IonTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4Geantino.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "RunAction.hh"
#include "G4IsotopeProperty.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::PrimaryGeneratorAction()
 : G4VUserPrimaryGeneratorAction()
 {
 //  fParticleGun(0)


	 G4int n_particle = 1;
	 fParticleGun= new G4ParticleGun(n_particle);


//-------감마랜덤-------------------------------------------------------------------------------


G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
G4String particleName;
G4ParticleDefinition* particle  = particleTable -> FindParticle(particleName = "gamma");
fParticleGun -> SetParticleDefinition(particle);



//-----------------------------------------------------------------------------------------

}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete fParticleGun;
}




//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
//--------감마랜덤---------------------------------------------------------------------

  //G4double phi = 2*CLHEP::pi*G4UniformRand();
  //G4double theta = CLHEP::pi*G4UniformRand();
  //fParticleGun -> SetParticleMomentumDirection(G4ThreeVector(std::sin(theta)*std::cos(phi),std::sin(theta)*std::sin(phi), std::cos(theta)));
int erg[15]={20, 30, 40, 60, 80, 100, 130, 160, 200, 240, 280, 320, 380, 420, 480};

for(int i=0;i<=15;i++)
{
	G4double cosTheta= -1+2*G4UniformRand();
	G4double phi = 2*CLHEP::pi*G4UniformRand();
	G4double sinTheta = sqrt(1-cosTheta*cosTheta);
	fParticleGun -> SetParticleMomentumDirection(G4ThreeVector(sinTheta*cos(phi),sinTheta*sin(phi),cosTheta));
	fParticleGun->SetParticlePosition(G4ThreeVector(500.*mm,500*mm,500*mm));
	fParticleGun->SetParticleEnergy(erg[i]*keV);
	fParticleGun->GeneratePrimaryVertex(anEvent);

}




//	fParticleGun->SetParticlePosition(G4ThreeVector(0.*mm,0.*mm,0.*mm));
//	fParticleGun -> SetParticleMomentumDirection(G4ThreeVector(0,0,1.));
//	fParticleGun->SetParticleEnergy(461*keV);
//	fParticleGun->GeneratePrimaryVertex(anEvent);

//	G4double cosTheta1= -1+2*G4UniformRand();
//	G4double phi1 = 2*CLHEP::pi*G4UniformRand();
//	G4double sinTheta1 = sqrt(1-cosTheta1*cosTheta1);
//	fParticleGun -> SetParticleMomentumDirection(G4ThreeVector(sinTheta1*cos(phi1),sinTheta1*sin(phi1),cosTheta));
//	fParticleGun->SetParticlePosition(G4ThreeVector(500.*mm,500*mm,500*mm));
//	fParticleGun->SetParticleEnergy(442*keV);
//	fParticleGun->GeneratePrimaryVertex(anEvent);

//------------------------------------------------------------------------------------	
	/*
	   for(int i=10;i<201;i++)
	   {
	   fParticleGun -> SetParticleEnergy(i*MeV);
	   fParticleGun -> SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));
	   fParticleGun -> GeneratePrimaryVertex(anEvent);
	   fParticleGun -> SetParticleMomentumDirection(G4ThreeVector(0.,0.,-1.));
	   fParticleGun -> GeneratePrimaryVertex(anEvent);
	   fParticleGun -> SetParticleMomentumDirection(G4ThreeVector(1.,0.,0.));
	   fParticleGun -> GeneratePrimaryVertex(anEvent);
	   }
	   */
	//fParticleGun->SetParticleEnergy(0*eV);
	//fParticleGun->GeneratePrimaryVertex(anEvent);
	//fParticleGun->SetParticlePosition(G4ThreeVector(0.*mm,0.*mm,0.*mm));
	//fParticleGun->SetParticleEnergy(10*MeV);
	//fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0,0,1));
	//fParticleGun->SetParticleMomentumDirection(G4ThreeVector(1,0,0));
	//fParticleGun->GeneratePrimaryVertex(anEvent);
	//	fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0,0,-1));
	//fParticleGun->GeneratePrimaryVertex(anEvent);
	
			

//-------------isotopes-------------------//
/*
		//G4int Z = 11, A = 22;
		//G4int Z = 27, A = 60;
		//G4int Z = 56, A = 133;
		G4int Z = 55, A = 137;
		//G4int Z = 63, A = 152;                
		//G4int Z = 52 , A = 136;                
		//G4int Z = 51, A = 138;                

		{                       
			fParticleGun->SetParticleEnergy(0*eV);
			fParticleGun->SetParticlePosition(G4ThreeVector(500.*mm,500.*mm,500.*mm));
			//fParticleGun->SetParticlePosition(G4ThreeVector(0.*mm,0.*mm,0.*mm));
			fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));

			G4double ionCharge   = 0.*eplus;
			G4double excitEnergy = 0.*keV;       

			G4ParticleDefinition* ion
				= G4IonTable::GetIonTable()->GetIon(Z,A,excitEnergy);
			fParticleGun->SetParticleDefinition(ion);
			fParticleGun->SetParticleCharge(ionCharge);
			fParticleGun->GeneratePrimaryVertex(anEvent);
			
		//	G4IsotopeProperty *fproperty = FindIsotope(Z, A,0,2);
		//	std::cout <<"!!!!!!!!!!!!!!!!!!!!!!!!!!"<<fproperty->GetLifeTime()<<std::endl;
		}
*/


//=============================La138=====================================
	
{


/*	
double seed_La[36];
double focus_po=500;

for(int i =0;i<36;i++)
{
	seed_La[i]=rand()%100000;
}

//double pos_cry[36][3]={{-0,36.1182,134.795},{-0,98.6768,98.6768},{-0,134.795,36.1182},{-0,134.795,-36.1182},{-0,98.6768,-98.6768},{-0,36.1182,-134.795},{-0,-36.1182,-134.795},{-0,-98.6768,-98.6768},{-0,-134.795,-36.1182},{-0,-134.795,36.1182},{-0,-98.6768,98.6768},{-0,-36.1182,134.795},{-80.0426,29.5863,110.418},{-80.0426,80.8313,80.8313},{-80.0426,110.418,29.5863},{-80.0426,110.418,-29.5863},{-80.0426,80.8313,-80.8313},{-80.0426,29.5863,-110.418},{-80.0426,-29.5863,-110.418},{-80.0426,-80.8313,-80.8313},{-80.0426,-110.418,-29.5863},{-80.0426,-110.418,29.5863},{-80.0426,-80.8313,80.8313},{-80.0426,-29.5863,110.418}};
double pos_cry[36][3]={{-0,30.9418,115.476},{-0,84.5346,84.5346},{-0,115.476,30.9418},{-0,115.476,-30.9418},{-0,84.5346,-84.5346},{-0,30.9418,-115.476},{-0,-30.9418,-115.476},{-0,-84.5346,-84.5346},{-0,-115.476,-30.9418},{-0,-115.476,30.9418},{-0,-84.5346,84.5346},{-0,-30.9418,115.476},{-59.775,26.7964,100.006},{-59.775,73.2091,73.2091},{-59.775,100.006,26.7964},{-59.775,100.006,-26.7964},{-59.775,73.2091,-73.2091},{-59.775,26.7964,-100.006},{-59.775,-26.7964,-100.006},{-59.775,-73.2091,-73.2091},{-59.775,-100.006,-26.7964},{-59.775,-100.006,26.7964},{-59.775,-73.2091,73.2091},{-59.775,-26.7964,100.006},{59.775,26.7964,100.006},{59.775,73.2091,73.2091},{59.775,100.006,26.7964},{59.775,100.006,-26.7964},{59.775,73.2091,-73.2091},{59.775,26.7964,-100.006},{59.775,-26.7964,-100.006},{59.775,-73.2091,-73.2091},{59.775,-100.006,-26.7964},{59.775,-100.006,26.7964},{59.775,-73.2091,73.2091},{59.775,-26.7964,100.006}};


for(int i=0;i<36;i++)
{
	//if(seed_La[i]<100)
	if(seed_La[i]<100)
	{
		fParticleGun->SetParticlePosition(G4ThreeVector(pos_cry[i][0]+focus_po,pos_cry[i][1]+focus_po,pos_cry[i][2]+focus_po));
		fParticleGun->SetParticleMomentumDirection(G4ThreeVector(1.,0.,0.));

		G4int Z = 57, A = 138;
		G4double ionCharge   = 0.*eplus;
		G4double excitEnergy = 0.*keV;

		G4ParticleDefinition* ion    = G4IonTable::GetIonTable()->GetIon(Z,A,excitEnergy);
		fParticleGun->SetParticleDefinition(ion);
		fParticleGun->SetParticleCharge(ionCharge);

		fParticleGun->GeneratePrimaryVertex(anEvent);
	}
}

*/
}

//====================================================================
	
	//create vertex
	//   

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
