function img1 = adaugaDrumVertical(img,drum)

img1 = zeros(size(img,1),size(img,2)+1,size(img,3),'uint8');

for i=1:size(img1,1)
        coloana = drum(i,2);
        img1(i,1:coloana-1,:) = img(i,1:coloana-1,:);
        img1(i,coloana,:) = img(i,coloana,:);
        img1(i,coloana+1:end,:) = img(i,coloana:end,:);
end
