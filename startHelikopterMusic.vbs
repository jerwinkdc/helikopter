set WshShell = CreateObject("WScript.Shell")

strCurDir = WshShell.CurrentDirectory
music = strCurDir & "\helikopter.wav"

WshShell.Run "wmplayer """ & music & """",0,True