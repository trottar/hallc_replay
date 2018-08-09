#define KaonYield_cxx
// The class definition in KaonYield.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("KaonYield.C")
// root> T->Process("KaonYield.C","some options")
// root> T->Process("KaonYield.C+")
//


#include "KaonYield.h"
#include <TStyle.h>
#include <TCanvas.h>
#include <TLine.h>

void KaonYield::Begin(TTree * /*tree*/)
{
  // The Begin() function is called at the start of the query.
  // When running with PROOF Begin() is only called on the client.
  // The tree argument is deprecated (on PROOF 0 is passed).

  TString option = GetOption();

  Info("Begin", "Starting Good particle Selection");
}

void KaonYield::SlaveBegin(TTree * /*tree*/)
{
  // The SlaveBegin() function is called after the Begin() function.
  // When running with PROOF SlaveBegin() is called on each slave server.
  // The tree argument is deprecated (on PROOF 0 is passed).

  TString option = GetOption();

  h2ROC1_Coin_Beta_noID_kaon = new TH2F("ROC1_Coin_Beta_noID_kaon","Kaon Coincident Time vs #beta for ROC1 (no particle ID);Time (ns);#beta",800,-40,40,200,0.0,2.0);
  h2ROC1_Coin_Beta_kaon = new TH2F("ROC1_Coin_Beta_kaon","Kaon Coincident Time vs #beta for ROC1;Time (ns);#beta",800,-40,40,200,0.0,2.0);
  h2ROC1_Coin_Beta_noID_pion = new TH2F("ROC1_Coin_Beta_noID_pion","Pion Coincident Time vs #beta for ROC1 (no particle ID);Time (ns);#beta",800,-40,40,200,0.0,2.0);
  h2ROC1_Coin_Beta_pion = new TH2F("ROC1_Coin_Beta_pion","Pion Coincident Time vs #beta for ROC1;Time (ns);#beta",800,-40,40,200,0.0,2.0);
  h2ROC1_Coin_Beta_noID_proton = new TH2F("ROC1_Coin_Beta_noID_proton","Proton Coincident Time vs #beta for ROC1 (no particle ID);Time (ns);#beta",800,-40,40,200,0.0,2.0);
  h2ROC1_Coin_Beta_proton = new TH2F("ROC1_Coin_Beta_proton","Proton Coincident Time vs #beta for ROC1;Time (ns);#beta",800,-40,40,200,0.0,2.0);

  h1HMS_electron        = new TH1F("HMS_electron","Normalized HMS Calorimeter Energy;Normalized Energy;Counts",200,0.01,1.5);
  h1HMS_electron_cut    = new TH1F("HMS_electron_cut","Normalized HMS Calorimeter Energy, Electrons Selected;Normalized Energy;Counts",200,0.01,1.5);

  h1SHMS_electron        = new TH1F("SHMS_electron","Normalized SHMS Calorimeter Energy;Normalized Energy;Counts",200,0.01,1.5);
  h1SHMS_electron_cut    = new TH1F("SHMS_electron_cut","Normalized SHM Calorimeter Energy, Electrons Removed;Normalized Energy;Counts",200,0.01,1.5);

  h2SHMSK_kaon            = new TH2F("SHMSK_kaon","NPE in SHMS Aerogel and Heavy Gas;Aerogel NPE;HGC NPE",50,0.1,25,50,0.1,10);
  h2SHMSK_kaon_cut        = new TH2F("SHMSK_kaon_cut","NPE in SHMS Aerogel and Heavy Gas, Kaons Selected;Aerogel NPE;HGC NPE",50,0.0,25,50,0.0,10);
  h2SHMSK_pion            = new TH2F("SHMSK_pion","NPE in SHMS Noble and Heavy Gas;Noble NPE;HGC NPE",50,0.1,25,50,0.1,10);
  h2SHMSK_pion_cut        = new TH2F("SHMSK_pion_cut","NPE in SHMS Noble and Heavy Gas, Pions Selected;Noble NPE;HGC NPE",50,0.0,25,50,0.0,10);

  h2SHMSpi_kaon            = new TH2F("SHMSpi_kaon","NPE in SHMS Aerogel and Heavy Gas;Aerogel NPE;HGC NPE",50,0.1,25,150,0.1,30);
  h2SHMSpi_kaon_cut        = new TH2F("SHMSpi_kaon_cut","NPE in SHMS Aerogel and Heavy Gas, Kaons Selected;Aerogel NPE;HGC NPE",50,0.0,25,150,0.0,30);
  h2SHMSpi_pion            = new TH2F("SHMSpi_pion","NPE in SHMS Noble and Heavy Gas;Noble NPE;HGC NPE",50,0.1,25,150,0.1,30);
  h2SHMSpi_pion_cut        = new TH2F("SHMSpi_pion_cut","NPE in SHMS Noble and Heavy Gas, Pions Selected;Noble NPE;HGC NPE",50,0.0,25,150,0.0,30);

  h2SHMSp_kaon            = new TH2F("SHMSp_kaon","NPE in SHMS Aerogel and Heavy Gas;Aerogel NPE;HGC NPE",50,0.1,25,50,0.1,10);
  h2SHMSp_kaon_cut        = new TH2F("SHMSp_kaon_cut","NPE in SHMS Aerogel and Heavy Gas, Kaons Selected;Aerogel NPE;HGC NPE",50,0.0,25,50,0.0,10);
  h2SHMSp_pion            = new TH2F("SHMSp_pion","NPE in SHMS Noble and Heavy Gas;Noble NPE;HGC NPE",50,0.1,25,50,0.1,10);
  h2SHMSp_pion_cut        = new TH2F("SHMSp_pion_cut","NPE in SHMS Noble and Heavy Gas, Pions Selected;Noble NPE;HGC NPE",50,0.0,25,50,0.0,10);

  h1SHMS_delta           = new TH1F("SHMS_delta","SHMS #delta;#delta;Counts",100,-50,50);
  h1SHMS_delta_cut       = new TH1F("SHMS_delta_cut","SHMS #delta Cut;#delta;Counts",100,-50,50);
  h1HMS_delta            = new TH1F("HMS_delta","HMS #delta;#delta;Counts",100,-50,50);
  h1HMS_delta_cut        = new TH1F("HMS_delta_cut","HMS #delta Cut;#delta;Counts",100,-50,50);

  h1mmissK                = new TH1F("mmissK","Missing mass;Mass (GeV/c^{2});Counts",200,0,2.0);
  h1mmissK_cut            = new TH1F("mmissK_cut","Missing mass with Cuts;Mass (GeV/c^{2});Counts",200,0.8,1.8);

  h1mmisspi                = new TH1F("mmisspi","Missing mass;Mass (GeV/c^{2});Counts",200,0,2.0);
  h1mmisspi_cut            = new TH1F("mmisspi_cut","Missing mass with Cuts;Mass (GeV/c^{2});Counts",200,0,3.0);

  h1mmissp                = new TH1F("mmissp","Missing mass;Mass (GeV/c^{2});Counts",200,-0.5,2.0);
  h1mmissp_cut            = new TH1F("mmissp_cut","Missing mass with Cuts;Mass (GeV/c^{2});Counts",200,-0.5,2.0);

  GetOutputList()->Add(h2ROC1_Coin_Beta_noID_kaon);
  GetOutputList()->Add(h2ROC1_Coin_Beta_kaon);
  GetOutputList()->Add(h2ROC1_Coin_Beta_noID_pion);
  GetOutputList()->Add(h2ROC1_Coin_Beta_pion);
  GetOutputList()->Add(h2ROC1_Coin_Beta_noID_proton);
  GetOutputList()->Add(h2ROC1_Coin_Beta_proton);
  GetOutputList()->Add(h1HMS_electron);
  GetOutputList()->Add(h1HMS_electron_cut);
  GetOutputList()->Add(h1SHMS_electron);
  GetOutputList()->Add(h1SHMS_electron_cut);
  GetOutputList()->Add(h2SHMSK_kaon);
  GetOutputList()->Add(h2SHMSK_kaon_cut);
  GetOutputList()->Add(h2SHMSK_pion);
  GetOutputList()->Add(h2SHMSK_pion_cut);
  GetOutputList()->Add(h2SHMSpi_kaon);
  GetOutputList()->Add(h2SHMSpi_kaon_cut);
  GetOutputList()->Add(h2SHMSpi_pion);
  GetOutputList()->Add(h2SHMSpi_pion_cut);
  GetOutputList()->Add(h2SHMSp_kaon);
  GetOutputList()->Add(h2SHMSp_kaon_cut);
  GetOutputList()->Add(h2SHMSp_pion);
  GetOutputList()->Add(h2SHMSp_pion_cut);
  GetOutputList()->Add(h1SHMS_delta);
  GetOutputList()->Add(h1SHMS_delta_cut);
  GetOutputList()->Add(h1HMS_delta);
  GetOutputList()->Add(h1HMS_delta_cut);
  GetOutputList()->Add(h1mmissK);
  GetOutputList()->Add(h1mmissK_cut);
  GetOutputList()->Add(h1mmisspi);
  GetOutputList()->Add(h1mmisspi_cut);
  GetOutputList()->Add(h1mmissp);
  GetOutputList()->Add(h1mmissp_cut);

}

Bool_t KaonYield::Process(Long64_t entry)
{
  // The Process() function is called for each entry in the tree (or possibly
  // keyed object in the case of PROOF) to be processed. The entry argument
  // specifies which entry in the currently loaded tree is to be processed.
  // When processing keyed objects with PROOF, the object is already loaded
  // and is available via the fObject pointer.
  //
  // This function should contain the \"body\" of the analysis. It can contain
  // simple or elaborate selection criteria, run algorithms on the data
  // of the event and typically fill histograms.
  //
  // The processing can be stopped by calling Abort().
  //
  // Use fStatus to set the return value of TTree::Process().
  //
  // The return value is currently not used.

  fReader.SetEntry(entry);

  //if (*fEvtType != 4) return kTRUE;
  
  h1HMS_electron->Fill(H_cal_etotnorm[0]);
  h1SHMS_electron->Fill(P_cal_etotnorm[0]);

  h2SHMSK_kaon->Fill(P_aero_npeSum[0],P_hgcer_npeSum[0]);
  h2SHMSK_pion->Fill(P_ngcer_npeSum[0],P_hgcer_npeSum[0]);
  h2SHMSpi_kaon->Fill(P_aero_npeSum[0],P_hgcer_npeSum[0]);
  h2SHMSpi_pion->Fill(P_ngcer_npeSum[0],P_hgcer_npeSum[0]);
  h2SHMSp_kaon->Fill(P_aero_npeSum[0],P_hgcer_npeSum[0]);
  h2SHMSp_pion->Fill(P_ngcer_npeSum[0],P_hgcer_npeSum[0]);
  
  h1SHMS_delta->Fill(P_gtr_dp[0]);
  h1HMS_delta->Fill(H_gtr_dp[0]);

  h1mmissK->Fill(sqrt(pow(emiss[0] + sqrt(pow(0.13957018,2) + pow(P_gtr_p[0],2)) - sqrt(pow(0.493677,2) + pow(P_gtr_p[0],2)),2)-pow(pmiss[0],2)));
  h1mmisspi->Fill(sqrt(pow(emiss[0],2)-pow(pmiss[0],2)));
  h1mmissp->Fill(sqrt(pow(emiss[0] + sqrt(pow(0.13957018,2) + pow(P_gtr_p[0],2)) - sqrt(pow(0.93828,2) + pow(P_gtr_p[0],2)),2)-pow(pmiss[0],2)));

  if (H_cal_etotnorm[0] < 0.9) return kTRUE;
  if (P_cal_etotnorm[0] > 0.6) return kTRUE;

  if (TMath::Abs(H_gtr_dp[0]) > 10.0) return kTRUE;
  if (P_gtr_dp[0] > 10.0 || P_gtr_dp[0] < -22.0) return kTRUE;

  h1HMS_electron_cut->Fill(H_cal_etotnorm[0]);
  h1SHMS_electron_cut->Fill(P_cal_etotnorm[0]);
  
  h1SHMS_delta_cut->Fill(P_gtr_dp[0]);
  h1HMS_delta_cut->Fill(H_gtr_dp[0]);

  if (P_aero_npeSum[0] > 1.5 && P_hgcer_npeSum[0] < 1.5) { //Event identified as Kaon
    h2ROC1_Coin_Beta_noID_kaon->Fill((CTime_eKCoinTime_ROC1[0] - 10.0),P_gtr_beta[0]); 

    if (abs(P_gtr_beta[0]-1.00) > 0.1) return kTRUE;
  
    if (abs((CTime_eKCoinTime_ROC1[0] - 10.0)) < 1.0) {
      h2ROC1_Coin_Beta_kaon->Fill((CTime_eKCoinTime_ROC1[0] - 10.0),P_gtr_beta[0]);
      h2SHMSK_kaon_cut->Fill(P_aero_npeSum[0],P_hgcer_npeSum[0]);
      h2SHMSK_pion_cut->Fill(P_ngcer_npeSum[0],P_hgcer_npeSum[0]);
      h1mmissK_cut->Fill(sqrt(pow(emiss[0] + sqrt(pow(0.13957018,2) + pow(P_gtr_p[0],2)) - sqrt(pow(0.493677,2) + pow(P_gtr_p[0],2)),2)-pow(pmiss[0],2)));
    }
  }

  if (P_ngcer_npeSum[0] < 1.5 && P_hgcer_npeSum[0] > 1.5) { //Event identified as Pion
    h2ROC1_Coin_Beta_noID_pion->Fill((CTime_ePiCoinTime_ROC1[0] - 10.0),P_gtr_beta[0]);
    
    if (abs(P_gtr_beta[0]-1.00) > 0.1) return kTRUE;
  
    if (abs((CTime_ePiCoinTime_ROC1[0] - 10.0)) < 1.0) {
      h2ROC1_Coin_Beta_pion->Fill((CTime_ePiCoinTime_ROC1[0] - 10.0),P_gtr_beta[0]);
      h2SHMSpi_kaon_cut->Fill(P_aero_npeSum[0],P_hgcer_npeSum[0]);
      h2SHMSpi_pion_cut->Fill(P_ngcer_npeSum[0],P_hgcer_npeSum[0]);
      h1mmisspi_cut->Fill(sqrt(pow(emiss[0],2)-pow(pmiss[0],2)));
    }
  }

  if (P_aero_npeSum[0] < 1.5 && P_hgcer_npeSum[0] < 1.5) { //Event identified as Proton
    h2ROC1_Coin_Beta_noID_proton->Fill((CTime_epCoinTime_ROC1[0] - 10.0),P_gtr_beta[0]);
    
    if (abs(P_gtr_beta[0]-1.00) > 0.1) return kTRUE;
  
    if (abs((CTime_epCoinTime_ROC1[0] - 10.0)) < 1.0) {
      h2ROC1_Coin_Beta_proton->Fill((CTime_epCoinTime_ROC1[0] - 10.0),P_gtr_beta[0]);
      h2SHMSp_kaon_cut->Fill(P_aero_npeSum[0],P_hgcer_npeSum[0]);
      h2SHMSp_pion_cut->Fill(P_ngcer_npeSum[0],P_hgcer_npeSum[0]);
      h1mmissp_cut->Fill(sqrt(pow(emiss[0] + sqrt(pow(0.13957018,2) + pow(P_gtr_p[0],2)) - sqrt(pow(0.93828,2) + pow(P_gtr_p[0],2)),2)-pow(pmiss[0],2)));
    }
  }

  return kTRUE;
}

void KaonYield::SlaveTerminate()
{
  // The SlaveTerminate() function is called after all entries or objects
  // have been processed. When running with PROOF SlaveTerminate() is called
  // on each slave server.

}

void KaonYield::Terminate()
{
  // The Terminate() function is the last function to be called during
  // a query. It always runs on the client, it can be used to present
  // the results graphically or save the results to file.

  Info("Terminate", "Outputting Good Kaon Selection");

  TCanvas *cKine = new TCanvas("Kine","Summary of Common Cuts");
  cKine->Divide(2,4);
  cKine->cd(1); h1HMS_delta->Draw();
  cKine->cd(2); h1HMS_delta_cut->Draw();
  cKine->cd(3); h1SHMS_delta->Draw();
  cKine->cd(4); h1SHMS_delta_cut->Draw();
  cKine->cd(5); h1HMS_electron->Draw();
  cKine->cd(6); h1HMS_electron_cut->Draw();
  cKine->cd(7); h1SHMS_electron->Draw();
  cKine->cd(8); h1SHMS_electron_cut->Draw();

  TCanvas *cID = new TCanvas("ID","Summary of Kaon Particle ID Cuts");
  cID->Divide(2,4);
  cID->cd(1); h2SHMSK_kaon->Draw("Colz");
  cID->cd(2); h2SHMSK_kaon_cut->Draw("Colz");
  cID->cd(3); h2SHMSK_pion->Draw("Colz");
  cID->cd(4); h2SHMSK_pion_cut->Draw("Colz");
  cID->cd(5); h2ROC1_Coin_Beta_noID_kaon->Draw("Colz");
  cID->cd(6); h2ROC1_Coin_Beta_kaon->Draw("Colz");
  cID->cd(7); h1mmissK->Draw();
  cID->cd(8); h1mmissK_cut->Draw();
  cID->Update();
  TLine *LambdaMass = new TLine(1.1156,0,1.1156,gPad->GetUymax()); 
  LambdaMass->SetLineColor(kBlack); LambdaMass->SetLineWidth(3);
  LambdaMass->Draw();
  TF1 *Lambda_Fit = new TF1("Lambda_Fit","[0]*exp(-0.5*((x-[1])/[2])*((x-[1])/[2]))",1.05,1.2);
  Lambda_Fit->SetParName(0,"Amplitude");
  Lambda_Fit->SetParName(1,"Mean");
  Lambda_Fit->SetParName(2,"Sigma");
  Lambda_Fit->SetParLimits(0,0.0,10000.0);
  Lambda_Fit->SetParLimits(1,0.9,1.0);
  Lambda_Fit->SetParLimits(2,0.0,1.0);
  Lambda_Fit->SetParameter(0,100);
  Lambda_Fit->FixParameter(1,1.1156);
  Lambda_Fit->SetParameter(2,0.011);
  h1mmissK_cut->Fit("Lambda_Fit","RMQ");

  TCanvas *cpiID = new TCanvas("piID","Summary of Pion Particle ID Cuts");
  cpiID->Divide(2,4);
  cpiID->cd(1); h2SHMSpi_kaon->Draw("Colz");
  cpiID->cd(2); h2SHMSpi_kaon_cut->Draw("Colz");
  cpiID->cd(3); h2SHMSpi_pion->Draw("Colz");
  cpiID->cd(4); h2SHMSpi_pion_cut->Draw("Colz");
  cpiID->cd(5); h2ROC1_Coin_Beta_noID_pion->Draw("Colz");
  cpiID->cd(6); h2ROC1_Coin_Beta_pion->Draw("Colz");
  cpiID->cd(7); h1mmisspi->Draw();
  cpiID->cd(8); h1mmisspi_cut->Draw();
  cpiID->Update();
  TLine *NeutronMass = new TLine(0.93957,0,0.93957,gPad->GetUymax()); 
  NeutronMass->SetLineColor(kBlack); NeutronMass->SetLineWidth(3);
  NeutronMass->Draw();
  TF1 *Neutron_Fit = new TF1("Neutron_Fit","[0]*exp(-0.5*((x-[1])/[2])*((x-[1])/[2]))",0.8,1.0);
  Neutron_Fit->SetParName(0,"Amplitude");
  Neutron_Fit->SetParName(1,"Mean");
  Neutron_Fit->SetParName(2,"Sigma");
  Neutron_Fit->SetParLimits(0,0.0,10000.0);
  Neutron_Fit->SetParLimits(1,0.9,1.0);
  Neutron_Fit->SetParLimits(2,0.0,1.0);
  Neutron_Fit->SetParameter(0,100);
  Neutron_Fit->FixParameter(1,0.93957);
  Neutron_Fit->SetParameter(2,0.011);
  h1mmisspi_cut->Fit("Neutron_Fit","RMQ");

  TCanvas *cpID = new TCanvas("pID","Summary of Proton Particle ID Cuts");
  cpID->Divide(2,4);
  cpID->cd(1); h2SHMSp_kaon->Draw("Colz");
  cpID->cd(2); h2SHMSp_kaon_cut->Draw("Colz");
  cpID->cd(3); h2SHMSp_pion->Draw("Colz");
  cpID->cd(4); h2SHMSp_pion_cut->Draw("Colz");
  cpID->cd(5); h2ROC1_Coin_Beta_noID_proton->Draw("Colz");
  cpID->cd(6); h2ROC1_Coin_Beta_proton->Draw("Colz");
  cpID->cd(7); h1mmissp->Draw();
  cpID->cd(8); h1mmissp_cut->Draw();

  cout << Form("Number of good kaon events: %.0f +/- %.0f\n",200*Lambda_Fit->Integral(1.05,1.2),sqrt(200*Lambda_Fit->Integral(1.05,1.2)));

  // values for controlling format
  const string sep = "	" ;
  const int total_width = 154;
  const string line = sep + string( total_width-1, '-' ) + '|' ;


  ofstream myfile1;
  myfile1.open ("kaonyieldVar", fstream::app);
  myfile1 <<
    left << 200*Lambda_Fit->Integral(1.05,1.2) << "\n";
  myfile1.close();
}
