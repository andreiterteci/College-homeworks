function imgRedimensionata = redimensioneazaImagine(img,parametri)
%redimensioneaza imaginea
%
%input: img - imaginea initiala
%       parametri - stuctura de defineste modul in care face redimensionarea 
%
% output: imgRedimensionata - imaginea redimensionata obtinuta


optiuneRedimensionare = parametri.optiuneRedimensionare;
metodaSelectareDrum = parametri.metodaSelectareDrum;
ploteazaDrum = parametri.ploteazaDrum;
culoareDrum = parametri.culoareDrum;

switch optiuneRedimensionare
    
    case 'micsoreazaLatime'
        numarPixeliLatime = parametri.numarPixeliLatime;
        imgRedimensionata = micsoreazaLatime(img,numarPixeliLatime,metodaSelectareDrum,ploteazaDrum,culoareDrum);
        
    case 'micsoreazaInaltime'
        img = imrotate(img,90);
        numarPixeliLatime = parametri.numarPixeliLatime;
        imgRedimensionata = micsoreazaLatime(img,numarPixeliLatime,metodaSelectareDrum,ploteazaDrum,culoareDrum);
        imgRedimensionata = imrotate(imgRedimensionata, -90);
        
    case 'maresteLatime'
         numarPixeliLatime = parametri.numarPixeliLatime;
         imgRedimensionata = maresteLatime(img,numarPixeliLatime,metodaSelectareDrum,ploteazaDrum,culoareDrum);
        
    case 'maresteInaltime'
        img = imrotate(img,90);
        numarPixeliInaltime = parametri.numarPixeliLatime;
        imgRedimensionata = maresteLatime(img,numarPixeliInaltime,metodaSelectareDrum,ploteazaDrum,culoareDrum);
        imgRedimensionata = imrotate(imgRedimensionata, -90);
    
    case 'amplificaContinut'
        img1 = imresize(img,2);
        [H,W,~] = size(img1);
        [h,w,~] = size(img);
        numarPixeliLatime = W - w;
        numarPixeliInaltime = H - h;
        imgRedimensionata = micsoreazaLatime(img1,numarPixeliLatime,metodaSelectareDrum,ploteazaDrum,culoareDrum);
        imgRedimensionata = imrotate(imgRedimensionata, -90);
        imgRedimensionata = micsoreazaLatime(imgRedimensionata,numarPixeliInaltime,metodaSelectareDrum,ploteazaDrum,culoareDrum);
        imgRedimensionata = imrotate(imgRedimensionata,90);
    case 'eliminaObiect'
       
    
end