




procedure keyboard_callback();
var
	b: pchar;
  key:byte;

begin

   if (ReadPortB($64) and $1)<>0 then
   begin

   key:= ReadPortB($60);
    if key in [0..86] then
    begin
       if  Application.Form.Active then
        begin

         Application.form.OnKeyDown(key);

        end;
      end;

   end;

 

end;



procedure init_keyboard();
begin
   RegisterISR(33, keyboard_callback);
end;