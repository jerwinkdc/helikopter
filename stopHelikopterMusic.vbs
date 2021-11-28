Dim objProcessSet, proname, process

On Error Resume Next

Set objProcessSet = GetObject ("winmgmts:{impersonationLevel=impersonate}").InstancesOf("Win32_Process")

For Each process In objProcessSet
  proname = LCase(process.Name)

  If proname = "wmplayer.exe" Then
    process.terminate()
    ShowSystemAlarm "terminated wmplayer"
  End If
Next
Set objProcessSet = Nothing