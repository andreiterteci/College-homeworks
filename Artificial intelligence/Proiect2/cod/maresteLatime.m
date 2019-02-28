function imgCopy = maresteLatime(img,numarPixeliLatime,metodaSelectareDrum,ploteazaDrum,culoareDrum)

matDrumuri = [];
imgCopy = img;
for i = 1:numarPixeliLatime
    disp(['Alegem drumul vertical numarul ' num2str(i) ' dintr-un total de ' num2str(numarPixeliLatime)]);
    E = calculeazaEnergie(img);
    drum = selecteazaDrumVertical(E,metodaSelectareDrum);
    matDrumuri = [matDrumuri drum(:,2)];   
    img = eliminaDrumVertical(img,drum);
end
    for idx = 1:size(matDrumuri,2)
        disp(['Alegem drumul vertical numarul ' num2str(i) ' dintr-un total de ' num2str(numarPixeliLatime)]);
        drum = [(1:size(matDrumuri,1))' matDrumuri(:,idx)];
        imgCopy = adaugaDrumVertical(imgCopy, drum);
        for k = 1:size(matDrumuri,1)
            for m = idx:size(matDrumuri,2)
                matDrumuri(k,m) = matDrumuri(k,m)+1;
            end
        end
    end
    