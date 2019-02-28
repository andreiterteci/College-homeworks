function d = selecteazaDrumVertical(E,metodaSelectareDrum)
%selecteaza drumul vertical ce minimizeaza functia cost calculate pe baza lui E
%
%input: E - energia la fiecare pixel calculata pe baza gradientului
%       metodaSelectareDrum - specifica metoda aleasa pentru selectarea drumului. Valori posibile:
%                           'aleator' - alege un drum aleator
%                           'greedy' - alege un drum utilizand metoda Greedy
%                           'programareDinamica' - alege un drum folosind metoda Programarii Dinamice
%
%output: d - drumul vertical ales

d = zeros(size(E,1),2);

switch metodaSelectareDrum
    case 'aleator'
        %pentru linia 1 alegem primul pixel in mod aleator
        linia = 1;
        %coloana o alegem intre 1 si size(E,2)
        coloana = randi(size(E,2));
        %punem in d linia si coloana coresponzatoare pixelului
        d(1,:) = [linia coloana];
        for i = 2:size(d,1)
            %alege urmatorul pixel pe baza vecinilor
            %linia este i
            linia = i;
            %coloana depinde de coloana pixelului anterior
            if d(i-1,2) == 1%pixelul este localizat la marginea din stanga
                %doua optiuni
                optiune = randi(2)-1;%genereaza 0 sau 1 cu probabilitati egale 
            elseif d(i-1,2) == size(E,2)%pixelul este la marginea din dreapta
                %doua optiuni
                optiune = randi(2) - 2; %genereaza -1 sau 0
            else
                optiune = randi(3)-2; % genereaza -1, 0 sau 1
            end
            coloana = d(i-1,2) + optiune;%adun -1 sau 0 sau 1: 
                                         % merg la stanga, dreapta sau stau pe loc
            d(i,:) = [linia coloana];
        end
    case 'greedy'
        linia = 1;
        coloana = randi(size(E,2));     
        d(1,:) = [linia coloana];
        for i = 2:size(d,1)          
            linia = i;           
            if d(i-1,2) == 1              
                [~,poz] = min (E(linia, coloana:coloana+1));
                optiune = poz - 1;
            elseif d(i-1,2) == size(E,2)
                [~,poz] = min (E(linia, coloana-1:coloana));
                optiune = poz - 2;
            else
                [~,poz] = min (E(linia, coloana-1:coloana+1));
                optiune = poz - 2;            
            end
            coloana = d(i-1,2) + optiune;
            d(i,:) = [linia coloana];
        end
        
        
    case 'programareDinamica'
       
	   M = zeros(size(E));
        M(1,:) = E(1,:);        
        for i  = 2:size(E,1)
            linia = i-1;           
            for coloana = 1:size(E,2)
                if coloana == 1
                    [val,~] = min([M(linia,coloana),M(linia,coloana+1)]);
                    M(i,coloana) = val + E(i,coloana);
                elseif coloana == size(E,2)
                    [val,~] = min([M(linia,coloana-1),M(linia,coloana)]);
                    M(i,coloana) = val + E(i,coloana);              
                else
                    [val,~] = min([M(linia,coloana-1),M(linia,coloana),M(linia,coloana+1)]);
                    M(i,coloana) = val + E(i,coloana);
                end
            end
        end
	liniaL = size(M,1);
	[~,coloanaL] = min(M(liniaL,:));
	d(liniaL,:) = [liniaL coloanaL];
	for i =liniaL-1:-1:1
		if coloanaL == 1
			[~,poz] = min([M(i,coloanaL),M(i,coloanaL+1)]);
			coloanaL = coloanaL + poz - 1;
            
		elseif coloanaL == size(M,2)
			[~,poz] = min([M(i,coloanaL-1),M(i,coloanaL)]);
			coloanaL = coloanaL + poz - 2;
		else
			[~,poz] = min([M(i,coloanaL-1),M(i,coloanaL),M(i,coloanaL+1)]);
			coloanaL = coloanaL + poz - 2;
		end
    d(i,:) = [i coloanaL];
end      
        
    otherwise
        error('Optiune pentru metodaSelectareDrum invalida');
end

end