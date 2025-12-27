PROGRAM su_search(input,output);

(*
   Program to search for distinct letter-prefixes
   in SU data, so that a list is produced which
   should not be reused
*)

TYPE string = ARRAY 1..6 of CHAR;
     slist  = ARRAY 1..100 of string;
     index  = 0..100;

VAR  a,b,c,blank,x: string;
     k,l : index;
     o   : slist;

PROCEDURE store(VAR a:string;
                VAR l:index;
                VAR o:slist);

VAR k:index;
    f:BOOLEAN;

BEGIN
f:=TRUE;
FOR k:=1 to l DO
   IF ok=a THEN f:=FALSE;
IF f THEN BEGIN l:=l+1; ol:=a END
END;

PROCEDURE db(VAR a: string);

VAR i,j: 1..6;

BEGIN
   WHILE a1=' ' DO BEGIN
      FOR j:=1 to 5 DO aj:=aj+1;
      a6:=' '
      END
END;

PROCEDURE dn(VAR a: string);

CONST blank='      ';
VAR i:1..6;

BEGIN
FOR i:=1 to 6 do
   IF ai IN '0'..'9' THEN ai:=' ';
IF a<>blank THEN db(a)
END;

(* Program begins here *)

BEGIN

a:='START ';
blank:='      ';
c:='END   ';
READLN; READLN; READLN;
x:=a;
l:=0;
WHILE a<>c DO BEGIN
   READ(a); READLN(b);
   dn(a); dn(b);
   IF a<>x THEN IF a<>blank THEN store(a,l,o);
   IF b<>a THEN IF b<>blank THEN store(b,l,o);
   x:=b
   END;
FOR k:=1 to l DO WRITELN(ok)
END.
