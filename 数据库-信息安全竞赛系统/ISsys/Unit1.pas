unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls, jpeg, DB, ADODB, DBTables;

type
  Tlogin = class(TForm)
    usr: TEdit;
    psd: TEdit;
    ok: TButton;
    cancel: TButton;
    back: TImage;
    username: TLabel;
    password: TLabel;
    db: TADOConnection;
    query: TADOQuery;
    procedure cancelClick(Sender: TObject);
    procedure okClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  login: Tlogin;

implementation

{$R *.dfm}


var
sql: String;
res: System.Boolean;

procedure Tlogin.okClick(Sender: TObject);
begin
      //label3.Caption := 'ѧ��λ��' + edit1.Text + '����Ϊ��' + edit2.Text;
      query.SQL.Clear;
      sql := 'select dbo.checkuser("' +  usr.Text + '", "' + psd.Text + '")';
      query.SQL.Text := sql;
      query.Open;
      res := query.Fields[0].AsBoolean;
end;

procedure Tlogin.cancelClick(Sender: TObject);
begin
    usr.Clear;
    psd.Clear;
    usr.SetFocus;
end;
end.
