<p>
  The following function starts an executable with a given command line. If
  the execution fails (non-0 return value from executable), the return value
  is <var>False</var>, and <var>GetLastError - $2000</var> is the return value
  from the executable. If the execution is successful (return value 0 from the
  executable), the return value is <var>True</var>.
</p>

<div class="frame">
<!-- Highlighted Pascal code generated by DelphiDabbler PasH -->
<pre class="pas-source"><span class="pas-kwd">function</span> ExecAndWait(sExe, sCommandLine: <span class="pas-kwd">string</span>): Boolean;
<span class="pas-kwd">var</span>
  dwExitCode: DWORD;
  tpiProcess: TProcessInformation;
  tsiStartup: TStartupInfo;
<span class="pas-kwd">begin</span>
  Result := False;
  FillChar(tsiStartup, SizeOf(TStartupInfo), <span class="pas-num">0</span>);
  tsiStartup.cb := SizeOf(TStartupInfo);
  <span class="pas-kwd">if</span> CreateProcess(PChar(fsExe), PChar(sCommandLine), <span class="pas-kwd">nil</span>, <span class="pas-kwd">nil</span>, False, <span class="pas-num">0</span>,
    <span class="pas-kwd">nil</span>, <span class="pas-kwd">nil</span>, tsiStartup, tpi) <span class="pas-kwd">then</span>
  <span class="pas-kwd">begin</span>
    <span class="pas-kwd">if</span> WAIT_OBJECT_0 = WaitForSingleObject(tpiProcess.hProcess, INFINITE) <span class="pas-kwd">then</span>
    <span class="pas-kwd">begin</span>
      <span class="pas-kwd">if</span> GetExitCodeProcess(tpiProcess.hProcess, dwExitCode) <span class="pas-kwd">then</span>
      <span class="pas-kwd">begin</span>
        <span class="pas-kwd">if</span> dwExitCode = <span class="pas-num">0</span> <span class="pas-kwd">then</span>
          Result := True
        <span class="pas-kwd">else</span>
          SetLastError(dwExitCode + <span class="pas-hex">$2000</span>);
      <span class="pas-kwd">end</span>;
    <span class="pas-kwd">end</span>;
    dwExitCode := GetLastError;
    CloseHandle(tpiProcess.hProcess);
    CloseHandle(tpiProcess.hThread);
    SetLastError(dwExitCode);
  <span class="pas-kwd">end</span>;
<span class="pas-kwd">end</span>;</pre>
</div>

<div class="xref">
  You can find a <?php
  echo DocPart::OffsiteTextLink(
    URL_SNIPPETSLIST . '?snippets=ExecAndWait', 'similar routine'
  );
  ?> in the <?php
  echo DocPart::OffsiteTextLink(URL_SNIPPETS, 'Code Snippets Database');
  ?>. For more control over the executed program see the <?php
  echo DocPart::SoftwareTextLink(
    'consoleapp', 'Console Application Runner Classes'
  );
  ?>.
</div>