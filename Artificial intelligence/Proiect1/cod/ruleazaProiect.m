%proiect REALIZAREA DE MOZAICURI
%

%%
%seteaza parametri pentru functie

%citeste imaginea care va fi transformata in mozaic
%puteti inlocui numele imaginii
params.imgReferinta = imread('D:\Facultate\IA\Proiect1\proiect1\data\Ex4\img1.jpg');

%seteaza directorul cu imaginile folosite la realizarea mozaicului
%puteti inlocui numele directorului
params.numeDirector = 'D:\Facultate\IA\Proiect1\proiect1\data\automobile\';

params.tipImagine = 'png';

%seteaza numarul de piese ale mozaicului pe orizontala
%puteti inlocui aceasta valoare
params.numarPieseMozaicOrizontala = 100;
%numarul de piese ale mozaicului pe verticala va fi dedus automat

%seteaza optiunea de afisare a pieselor mozaicului dupa citirea lor din
%director
params.afiseazaPieseMozaic = 0;

%seteaza modul de aranjare a pieselor mozaicului
%optiuni: 'aleator','caroiaj'
params.modAranjare = 'caroiaj';

%seteaza criteriul dupa care realizeze mozaicul
%optiuni: 'aleator','distantaCuloareMedie'
params.criteriu = 'distantaCuloareMedie';

%%
%apeleaza functia principala
imgMozaic = construiesteMozaic(params);

imwrite(imgMozaic,'mozaic.jpg');
figure, imshow(imgMozaic)