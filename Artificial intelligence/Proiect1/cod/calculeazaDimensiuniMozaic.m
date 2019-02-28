function params = calculeazaDimensiuniMozaic(params)
%calculeaza dimensiunile mozaicului
%obtine si imaginea de referinta redimensionata avand aceleasi dimensiuni
%ca mozaicul

%completati codul Matlab
[inaltimePiesa,latimePiesa,~] = size(params.pieseMozaic(:,:,:,1));
[inaltimeImagine,latimeImagine,~] = size(params.imgReferinta);

%calculeaza automat numarul de piese pe verticala
params.numarPieseMozaicVerticala = round((inaltimeImagine * params.numarPieseMozaicOrizontala * latimePiesa)/(inaltimePiesa*latimeImagine));

%calculeaza si imaginea de referinta redimensionata avand aceleasi dimensiuni ca mozaicul
params.imgReferintaRedimensionata = imresize(params.imgReferinta,[inaltimePiesa*params.numarPieseMozaicVerticala,latimePiesa*params.numarPieseMozaicOrizontala]);