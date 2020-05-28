<p>
  Here's an easy way to do it: create a timer and put this code in the
  <var>OnTimer</var> event:
</p>

<div class="frame">
<!-- Highlighted Pascal code generated by DelphiDabbler PasH -->
<pre class="pas-source"><span class="pas-kwd">var</span>
<span class="pas-space">  </span><span class="pas-ident">Trk</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">Min</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">Sec</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">Word</span><span class="pas-sym">;</span>
<span class="pas-kwd">begin</span>
<span class="pas-space">  </span><span class="pas-kwd">with</span><span class="pas-space"> </span><span class="pas-ident">MediaPlayer1</span><span class="pas-space"> </span><span class="pas-kwd">do</span>
<span class="pas-space">  </span><span class="pas-kwd">begin</span>
<span class="pas-space">    </span><span class="pas-ident">Trk</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">MCI_TMSF_TRACK</span><span class="pas-sym">(</span><span class="pas-ident">Position</span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-space">    </span><span class="pas-ident">Min</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">MCI_TMSF_MINUTE</span><span class="pas-sym">(</span><span class="pas-ident">Position</span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-space">    </span><span class="pas-ident">Sec</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">MCI_TMSF_SECOND</span><span class="pas-sym">(</span><span class="pas-ident">Position</span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-space">    </span><span class="pas-ident">Label1</span><span class="pas-sym">.</span><span class="pas-ident">Caption</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">Format</span><span class="pas-sym">(</span><span class="pas-str">'%.2d'</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-sym">[</span><span class="pas-ident">Trk</span><span class="pas-sym">]</span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-space">    </span><span class="pas-ident">Label2</span><span class="pas-sym">.</span><span class="pas-ident">Caption</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">Format</span><span class="pas-sym">(</span><span class="pas-str">'%.2d:%.2d'</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-sym">[</span><span class="pas-ident">Min</span><span class="pas-sym">,</span><span class="pas-ident">Sec</span><span class="pas-sym">]</span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-kwd">end</span><span class="pas-sym">;</span>
<span class="pas-kwd">end</span><span class="pas-sym">;</span></pre>
</div>

<p>
  Add <var>MMSystem</var> to the uses clause of the unit. The code will show
  the current track and time.
</p>