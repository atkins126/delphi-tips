<p>
  This is a very simple method to create a new drive which links to a folder, 
  for example: let's say we want a new drive letter (<code>W</code>) which 
  points to our Delphi components folder (<code>D:\Delphi\Components\</code>).
  Create a new VCL application, drop 2 buttons on the form, change caption of 
  <var>Button1</var> to <code>CreateDrive</code> and the caption of 
  <var>Button2</var> to <code>RemoveDrive</code>, paste the fallowing 3 methods 
  after the <strong>implementation</strong> keyword.
</p>

<div class="frame">
<!-- Highlighted Pascal code generated by DelphiDabbler PasHi -->
<div class="pas-source">
<pre class="line"><span class="pas-kwd">function</span><span class="pas-space"> </span><span class="pas-ident">SystemDir</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-kwd">string</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-kwd">begin</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-comment">(* get system32 folder *)</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-ident">SetLength</span><span class="pas-sym">(</span><span class="pas-ident">Result</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">MAX_PATH</span><span class="pas-sym">)</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-ident">GetSystemDirectory</span><span class="pas-sym">(</span><span class="pas-sym">@</span><span class="pas-ident">Result</span><span class="pas-sym">[</span><span class="pas-num">1</span><span class="pas-sym">]</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">MAX_PATH</span><span class="pas-sym">)</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-kwd">end</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space"> </span></pre>
<pre class="line"><span class="pas-kwd">procedure</span><span class="pas-space"> </span><span class="pas-ident">DriveLinkCreate</span><span class="pas-sym">(</span><span class="pas-kwd">const</span><span class="pas-space"> </span><span class="pas-ident">Drive</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">Char</span><span class="pas-sym">;</span><span class="pas-space"> </span><span class="pas-kwd">const</span><span class="pas-space"> </span><span class="pas-ident">Path</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-kwd">String</span><span class="pas-sym">)</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-kwd">var</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-ident">Param</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-kwd">String</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-kwd">begin</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-comment">(* format the call parameter *)</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-ident">Param</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">Format</span><span class="pas-sym">(</span><span class="pas-str">'%s: &quot;%s&quot;'</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-sym">[</span><span class="pas-ident">Drive</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">Path</span><span class="pas-sym">]</span><span class="pas-sym">)</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-comment">(* and bang! we get a new drive *)</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-ident">ShellExecute</span><span class="pas-sym">(</span><span class="pas-num">1</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-str">'open'</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-str">'subst'</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">PChar</span><span class="pas-sym">(</span><span class="pas-ident">Param</span><span class="pas-sym">)</span><span class="pas-sym">,</span></pre>
<pre class="line"><span class="pas-space">    </span><span class="pas-ident">PChar</span><span class="pas-sym">(</span><span class="pas-ident">SystemDir</span><span class="pas-sym">)</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-num">0</span><span class="pas-sym">)</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-kwd">end</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space"> </span></pre>
<pre class="line"><span class="pas-kwd">procedure</span><span class="pas-space"> </span><span class="pas-ident">DriveLinkRemove</span><span class="pas-sym">(</span><span class="pas-kwd">const</span><span class="pas-space"> </span><span class="pas-ident">Drive</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">Char</span><span class="pas-sym">)</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-kwd">var</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-ident">Param</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-kwd">String</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-kwd">begin</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-comment">(* format the call parameter with the /d option</span></pre>
<pre class="line"><span class="pas-comment">     which stands for delete *)</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-ident">Param</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">Format</span><span class="pas-sym">(</span><span class="pas-str">'%s: /d'</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-sym">[</span><span class="pas-ident">Drive</span><span class="pas-sym">]</span><span class="pas-sym">)</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-comment">(* now we remove the virtual drive *)</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-ident">ShellExecute</span><span class="pas-sym">(</span><span class="pas-num">1</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-str">'open'</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-str">'subst'</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">PChar</span><span class="pas-sym">(</span><span class="pas-ident">Param</span><span class="pas-sym">)</span><span class="pas-sym">,</span></pre>
<pre class="line"><span class="pas-space">    </span><span class="pas-ident">PChar</span><span class="pas-sym">(</span><span class="pas-ident">SystemDir</span><span class="pas-sym">)</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-num">0</span><span class="pas-sym">)</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-kwd">end</span><span class="pas-sym">;</span></pre>
</div>
</div>

<p>
  Now press <span class="smallcaps">F12</span> to see the form, double-click the 
  <code>CreateDrive</code> button and paste the following code:
</p>

<div class="frame">
<!-- Highlighted Pascal code generated by DelphiDabbler PasHi -->
<div class="pas-source">
<pre class="line"><span class="pas-space">  </span><span class="pas-ident">DriveLinkCreate</span><span class="pas-sym">(</span><span class="pas-str">'W'</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-str">'D:\Delphi\Components'</span><span class="pas-sym">)</span><span class="pas-sym">;</span></pre>
</div>
</div>

<p>
  Replace <code>D:\Delphi\Components</code> with your delphi component folder,
  press <span class="smallcaps">F12</span> again and double-click the 
  <code>RemoveDrive</code> button and paste this code:
</p>

<div class="frame">
<!-- Highlighted Pascal code generated by DelphiDabbler PasHi -->
<div class="pas-source">
<pre class="line"><span class="pas-space">  </span><span class="pas-ident">DriveLinkRemove</span><span class="pas-sym">(</span><span class="pas-str">'W'</span><span class="pas-sym">)</span><span class="pas-sym">;</span></pre>
</div>
</div>

<p>
  Don't forget to add <var>ShellApi</var> to uses clause.
</p>