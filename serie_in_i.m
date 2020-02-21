function res= serie_in_i(I,N)
  r=zeros(rows(I),1)
  for i= 1:rows(I) 
    i
    r(i,:)=(4/N)*(1/(1+((i-0.5)/N)^2))
  end
  res=sum(r)
end
