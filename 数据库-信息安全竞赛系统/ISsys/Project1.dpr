program Project1;

uses
  Forms,
  log in 'log.pas' {Form1},
  reg in 'reg.pas' {regist};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(Tlogin, login);
  //Application.CreateForm(Tlogin, login);
  //Application.CreateForm(TForm2, Form2);
  Application.Run;
end.
