/**
  \class PHEvtGenDecayer

  \brief PH wrapper for EvtGen Decayer

Authors: Xiaozhi Bai (xiaozhi@uic.edu),
Mustafa Mustafa (mmustafa@lbl.gov)
Zhaozhong Shi for Modification
*/

#ifndef PHEVTGENDECAYER_H
#define PHEVTGENDECAYER_H

#include <cstddef>

#include <TVirtualMCDecayer.h>
#include <TString.h>
#include <EvtGen/EvtGen.hh>
#include <TLorentzVector.h>
#include <EvtGenBase/EvtSimpleRandomEngine.hh>
#include <EvtGenBase/EvtRandomEngine.hh>

class TLorentzVector;
class TClonesArray;
class EvtStdlibRandomEngine;
class EvtParticle;
class EvtRandomEngine;

class PHEvtGenDecayer : public TVirtualMCDecayer
{
	public:
		PHEvtGenDecayer(EvtGen* evtGen = NULL);
		~PHEvtGenDecayer();
		void Init();
		void Decay(Int_t pdgId, TLorentzVector* p);
		Int_t ImportParticles(TClonesArray* particles);
		// virtual void SetForceDecay(Int_t type);
		// virtual void ForceDecay();
		// virtual void ReadDecayTable();
		// virtual Float_t GetPartialBranchingRatio(Int_t ipart);
		Float_t GetLifetime(Int_t pdgid);

		void setVertex(TLorentzVector* r);
		void setDecayTable(TString decayTable);
		void ClearEvent();
		void AppendParticle(Int_t pdg, TLorentzVector* _p);	
		void SetDecayTable(TString decayTable);
		void SetVertex(TLorentzVector* r);	


	private:
		// EvtStdlibRandomEngine* mEvtGenRandomEngine;
		EvtGen* mEvtGen = NULL;	
		EvtRandomEngine  * mEvtGenRandomEngine = NULL;
		EvtParticle* mParticle;
		TLorentzVector * mVertex = NULL;   
		bool mOwner;
		bool mDebug = false; 
		TLorentzVector * r_init = new TLorentzVector;   
};



inline void PHEvtGenDecayer::setDecayTable(TString decayTable) { mEvtGen->readUDecay(decayTable); }
inline void PHEvtGenDecayer::setVertex(TLorentzVector* r) {r_init->SetXYZT(r->X(),r->Y(),r->Z(),r->T()); }

#endif  /* PHEVTGENDECAYER_H */

