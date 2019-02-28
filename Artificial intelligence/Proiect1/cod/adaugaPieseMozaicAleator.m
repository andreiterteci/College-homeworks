function imgMozaic = adaugaPieseMozaicAleator(params)
%
%tratati si cazul in care imaginea de referinta este gri (are numai un canal)

imgMozaic = uint8(zeros(size(params.imgReferintaRedimensionata)));
[H,W,C,N] = size(params.pieseMozaic);
[h,w,c] = size(params.imgReferintaRedimensionata);

switch(params.criteriu)
    case 'aleator'
        %pune o piese aleatoare in mozaic, nu tine cont de nimic
        nrTotalPiese =size(params.imgReferintaRedimensionata,1)*size(params.imgReferintaRedimensionata,2);
        nrPieseAdaugate = 0;
        locatiiPixeli = zeros(size(params.imgReferintaRedimensionata,1),size(params.imgReferintaRedimensionata,2));
        notDone = 1;
        while notDone
            locatiiGoale = find(locatiiPixeli==0);
            if isempty(locatiiGoale)
                notDone = 0;
            else
                locatiiCandidat = unique(randi(numel(locatiiGoale),1,500));
                
                % inlocuim
                locatiiPixeli(locatiiGoale(locatiiCandidat)) = 1;
                
                [row,col] = ind2sub([size(params.imgReferintaRedimensionata,1),size(params.imgReferintaRedimensionata,2)],locatiiGoale(locatiiCandidat));
                
                for i = 1: numel(locatiiCandidat)
                    % includ in imaginea de referinta piese
                    linieStart = max(row(i)-H/2-1,1);
                    linieEnd = min(row(i)+H/2-1,size(params.imgReferintaRedimensionata,1));
                    coloanaStart = max(col(i)-W/2-1,1);
                    coloanaEnd = min(col(i)+W/2-1,size(params.imgReferintaRedimensionata,2));
                    pozs = zeros(size(params.pieseMozaic(:,:,:,1),1),size(params.pieseMozaic(:,:,:,1),2));
                    if linieEnd - linieStart<size(params.pieseMozaic(:,:,:,1),1),
                        pozs(size(params.pieseMozaic(:,:,:,1),1)-(linieEnd - linieStart)+1:end,:) = ...
                            pozs(size(params.pieseMozaic(:,:,:,1),1)-(linieEnd - linieStart)+1:end,:) + 1;
                    end
                    if coloanaEnd-coloanaStart < size(params.pieseMozaic(:,:,:,1),2),
                        pozs(:,size(params.pieseMozaic(:,:,:,1),2) - (coloanaEnd-coloanaStart)+1:end) = ...
                            pozs(:,size(params.pieseMozaic(:,:,:,1),2) - (coloanaEnd-coloanaStart)+1:end) + 1;
                    end
                    [linii,coloane] = find(pozs==max(pozs(:)));
                    indice = randi(N);
                    toAdd = params.pieseMozaic(linii(1):linii(end),coloane(1):coloane(end),:,indice);
                    try
                        imgMozaic(linieStart:linieEnd-1,coloanaStart:coloanaEnd-1,:) =  toAdd;
                    catch
                        1
                    end;
                end
                nrPieseAdaugate = numel(locatiiGoale);
                fprintf('Mozaicul mai are atatia pixeli descoperiti ... %2.2f%% \n',100*nrPieseAdaugate/nrTotalPiese);
            end
        end
        
        
    case 'distantaCuloareMedie'
        %completati codul Matlab
        for i = 1: size(params.pieseMozaic,4)
            vmR = mean(mean(params.pieseMozaic(:,:,1,i)));
            vmG = mean(mean(params.pieseMozaic(:,:,2,i)));
            vmB = mean(mean(params.pieseMozaic(:,:,3,i)));
            
            CuloareMediePiese(i,:) = [vmR vmG,vmB];
        end
        %             params.imgReferintaRedimensionataRedimensionata
        
        nrTotalPiese =size(params.imgReferintaRedimensionata,1)*size(params.imgReferintaRedimensionata,2);
        nrPieseAdaugate = 0;
        locatiiPixeli = zeros(size(params.imgReferintaRedimensionata,1),size(params.imgReferintaRedimensionata,2));
        notDone = 1;
        while notDone
            locatiiGoale = find(locatiiPixeli==0);
            if isempty(locatiiGoale)
                notDone = 0;
            else
                locatiiCandidat = unique(randi(numel(locatiiGoale),1,5000));
                
                % inlocuim
                locatiiPixeli(locatiiGoale(locatiiCandidat)) = 1;
                
                [row,col] = ind2sub([size(params.imgReferintaRedimensionata,1),size(params.imgReferintaRedimensionata,2)],locatiiGoale(locatiiCandidat));
                
                for i = 1: numel(locatiiCandidat)
                    % includ in imaginea de referinta piese
                    linieStart = max(row(i)-H/2-1,1);
                    linieEnd = min(row(i)+H/2-1,size(params.imgReferintaRedimensionata,1));
                    coloanaStart = max(col(i)-W/2-1,1);
                    coloanaEnd = min(col(i)+W/2-1,size(params.imgReferintaRedimensionata,2));
                    pozs = zeros(size(params.pieseMozaic(:,:,:,1),1),size(params.pieseMozaic(:,:,:,1),2));
                    if linieEnd - linieStart<size(params.pieseMozaic(:,:,:,1),1),
                        pozs(size(params.pieseMozaic(:,:,:,1),1)-(linieEnd - linieStart)+1:end,:) = ...
                            pozs(size(params.pieseMozaic(:,:,:,1),1)-(linieEnd - linieStart)+1:end,:) + 1;
                    end
                    if coloanaEnd-coloanaStart < size(params.pieseMozaic(:,:,:,1),2),
                        pozs(:,size(params.pieseMozaic(:,:,:,1),2) - (coloanaEnd-coloanaStart)+1:end) = ...
                            pozs(:,size(params.pieseMozaic(:,:,:,1),2) - (coloanaEnd-coloanaStart)+1:end) + 1;
                    end
                    [linii,coloane] = find(pozs==max(pozs(:)));
                    
                    
                    %% %%
                    fereastra = params.imgReferintaRedimensionata(linieStart:linieEnd-1,coloanaStart:coloanaEnd-1,:);
                    fmR = mean(mean(fereastra(:,:,1)));
                    fmG = mean(mean(fereastra(:,:,2)));
                    fmB = mean(mean(fereastra(:,:,3)));

                    % Calculez dist euclidiana
                    for k = 1:size(CuloareMediePiese,1)
                        de(k) = sqrt(sum( (CuloareMediePiese(k,:)-[fmR, fmG, fmB]).^2 )) ;
                    end

                    de2 = sqrt(sum( ((CuloareMediePiese-repmat([fmR, fmG, fmB],[size(CuloareMediePiese,1),1])).^2 ) ,2));

                    % Aleg cea mai mica valoare din de
                    [~, locatii] = min(de);

                    %
                    toAdd = params.pieseMozaic(linii(1):linii(end),coloane(1):coloane(end),:,locatii(1));
                    imgMozaic(linieStart:linieEnd-1,coloanaStart:coloanaEnd-1,:) =  toAdd;       
                end
                figure(1); imshow(imgMozaic)
                pause(1)
                nrPieseAdaugate = numel(locatiiGoale);
                fprintf('Mozaicul mai are atatia pixeli descoperiti ... %2.2f%% \n',100*nrPieseAdaugate/nrTotalPiese);
            end
        end
        
    otherwise
        printf('EROARE, optiune necunoscuta \n');
        
end