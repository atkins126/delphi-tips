<p>
  This code shows how to displays the Windows Disconnect Network Drives dialog
  box.
</p>

<p>
  If the user clicks OK the selected network drive is disconnected and True
  is returned. If the user cancels or there is an error False is returned.
  <var>OwnerHandle</var> is the handle of the window that owns the dialog box.
</p>

<div class="frame">
<!-- Highlighted Pascal code generated by DelphiDabbler PasHi -->
<pre class="pas-source"><span class="pas-kwd">function</span><span class="pas-space"> </span><span class="pas-ident">DisconnectNetworkDriveDialog</span><span class="pas-sym">(</span><span class="pas-kwd">const</span><span class="pas-space"> </span><span class="pas-ident">OwnerHandle</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">THandle</span><span class="pas-sym">)</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">Boolean</span><span class="pas-sym">;</span>
<span class="pas-kwd">begin</span>
<span class="pas-space">  </span><span class="pas-ident">Result</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">WNetDisconnectDialog</span><span class="pas-sym">(</span>
<span class="pas-space">    </span><span class="pas-ident">OwnerHandle</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">RESOURCETYPE_DISK</span>
<span class="pas-space">  </span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-sym">=</span><span class="pas-space"> </span><span class="pas-ident">NO_ERROR</span><span class="pas-sym">;</span>
<span class="pas-kwd">end</span><span class="pas-sym">;</span></pre>
</div>