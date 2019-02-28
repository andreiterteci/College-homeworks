function E = calculeazaEnergie(img)
%calculeaza energia la fiecare pixel pe baza gradientului
%input: img - imaginea initiala
%output: E - energia

%urmati urmatorii pasi:
%transformati imaginea in grayscale
%folositi un filtru sobel pentru a calcula gradientul in directia x si y
%calculati magnitudinea gradientului
%E - energia = gradientul imaginii

%completati aici codul vostru

if size(img, 3) == 3
        img = rgb2gray(img);
end
f = fspecial('sobel');
dx = imfilter(double(img),f);
dy = imfilter(double(img),f');

E = abs(dx) + abs(dy);