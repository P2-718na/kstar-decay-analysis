void kstar_decay_4_1() {
  // Carica i dati salvati da file
  TFile* histograms = new TFile("../histograms/kstar-decay-hist.root","READ");

  // Importa i grafici necessari per [4.1]
  TH1F* ParticleDist     = (TH1F*)histograms->Get("ParticleDist");
  TH1F* AzimuthAngleDist = (TH1F*)histograms->Get("AzimuthAngleDist");
  TH1F* PolarAngleDist   = (TH1F*)histograms->Get("PolarAngleDist");
  TH1F* MomentumDist     = (TH1F*)histograms->Get("MomentumDist");

  // Imposta lo stile
  gStyle->SetOptFit(1111);
  gStyle->SetOptStat("neM");

  // Crea una canvas per visualizzare i grafici e la divide in 4
  TCanvas* cv = new TCanvas("cv1", "", 1200, 800);
  cv->Divide(2, 2);

  cv->cd(1);
  // Crea una pie per organizzare i dati
  TPie * particleDistPie = new TPie(ParticleDist);

  // Imposta lo stile
  int colors[] = {2, 63, 65, 222, 224, 71, 75, 79};
  particleDistPie->SetTitle("Grafico B.1. Numero di particelle generate");
  particleDistPie->SetRadius(.25);
  particleDistPie->SetValueFormat("%.0f");
  particleDistPie->SetLabelFormat("%txt: %val (%perc)");
  particleDistPie->SortSlices();
  particleDistPie->SetFillColors(colors);
  particleDistPie->Draw(); // Richiesta solo qua, non dove faccio già chiamata a Fit();

  cv->cd(2); // Questo deve stare prima della chiamata a Fit(), altrimenti le cose si rompono.
  // Esegue il fit del grafico e lo disegna
  AzimuthAngleDist->Fit("pol0", "Q");
  AzimuthAngleDist->SetFillColor(7);
  AzimuthAngleDist->SetTitle("Grafico B.2. Distribuzione degli angoli azimutali e relativo fit;Valore angolo (radianti);Numero occorrenze");

  cv->cd(3);
  // Esegue il fit del grafico e lo disegna
  PolarAngleDist->Fit("pol0", "Q");
  PolarAngleDist->SetFillColor(7);
  PolarAngleDist->SetTitle("Grafico B.3. Distribuzione degli angoli polari e relativo fit;Valore angolo (radianti);Numero occorrenze");

  cv->cd(4);
  // Esegue il fit del grafico e lo disegna.
  TFitResultPtr r = MomentumDist->Fit("expo", "SQ");
  // Stampa il parametro con l'errore, visto che non compare nella legenda.
  cout << "tau = " << r->Parameter(1) << " +/- " << r->ParError(1) << endl;
  MomentumDist->SetFillColor(7);
  MomentumDist->SetTitle("Grafico B.4. Distribuzione del modulo dell'impulso e relativo fit;Modulo dell'impulso (GeV/c);Numero occorrenze");

  // Disegna la canvas
  cv->Draw();
}