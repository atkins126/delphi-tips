<p>
  I once got around this silly limitation by writing a wrapper procedure that
  would figure out where each dot or dash belonged, and draw many tiny line
  segments using a solid pen. One of the parameters to the procedure was a
  string indicating the pattern, which looked like morse code (any arrangement
  of dots and dashes is allowed).
</p>

<p>
  However, the procedure is ugly. It will handle polylines, and if a polyline
  vertex falls right in the middle of a dash, then the dash will bend around
  the corner correctly.
</p>

<p>
  The <var>LineTo</var> method of <var>TCanvas</var> cannot reliably render
  dashed lines more than one pixel wide. This procedure provides a workaround.
</p>

<div class="frame">
<!-- Highlighted Pascal code generated by DelphiDabbler PasH -->
<pre class="pas-source"><span class="pas-comment">{Copyright (c) 1996 G. Williams}</span>

<span class="pas-kwd">procedure</span><span class="pas-space"> </span><span class="pas-ident">PlotDashedLine</span><span class="pas-sym">(</span><span class="pas-kwd">const</span><span class="pas-space"> </span><span class="pas-ident">Canvas</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">TCanvas</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-kwd">const</span><span class="pas-space"> </span><span class="pas-ident">Vertices</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-kwd">array</span><span class="pas-space"> </span><span class="pas-kwd">of</span><span class="pas-space"> </span><span class="pas-ident">TPoint</span><span class="pas-sym">;</span><span class="pas-space"> </span><span class="pas-kwd">const</span><span class="pas-space"> </span><span class="pas-ident">Pattern</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-kwd">String</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-kwd">const</span><span class="pas-space"> </span><span class="pas-ident">DashLength</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">Integer</span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-kwd">var</span>
<span class="pas-space">  </span><span class="pas-ident">PenDown</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">Boolean</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-indent">Index</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">Integer</span><span class="pas-sym">;</span>

<span class="pas-space">  </span><span class="pas-kwd">procedure</span><span class="pas-space"> </span><span class="pas-ident">PlotTo</span><span class="pas-sym">(</span><span class="pas-kwd">const</span><span class="pas-space"> </span><span class="pas-ident">Position</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">TPoint</span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-kwd">begin</span>
<span class="pas-space">    </span><span class="pas-kwd">with</span><span class="pas-space"> </span><span class="pas-ident">Canvas</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">Position</span><span class="pas-space"> </span><span class="pas-kwd">do</span>
<span class="pas-space">      </span><span class="pas-kwd">if</span><span class="pas-space"> </span><span class="pas-sym">(</span><span class="pas-ident">PenDown</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-kwd">then</span>
<span class="pas-space">        </span><span class="pas-ident">LineTo</span><span class="pas-sym">(</span><span class="pas-ident">X</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">Y</span><span class="pas-sym">)</span>
<span class="pas-space">      </span><span class="pas-kwd">else</span>
<span class="pas-space">        </span><span class="pas-ident">MoveTo</span><span class="pas-sym">(</span><span class="pas-ident">X</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">Y</span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-kwd">end</span><span class="pas-sym">;</span>

<span class="pas-space">  </span><span class="pas-kwd">function</span><span class="pas-space"> </span><span class="pas-ident">Advance</span><span class="pas-sym">(</span><span class="pas-kwd">const</span><span class="pas-space"> </span><span class="pas-ident">Distance</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">Integer</span><span class="pas-sym">)</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">Boolean</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-kwd">var</span>
<span class="pas-space">    </span><span class="pas-ident">DistanceRemaining</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">Single</span><span class="pas-sym">;</span>
<span class="pas-space">    </span><span class="pas-ident">DistanceToNextVertex</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">Single</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-kwd">begin</span>
<span class="pas-space">    </span><span class="pas-ident">Result</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">false</span><span class="pas-sym">;</span>
<span class="pas-space">    </span><span class="pas-ident">DistanceRemaining</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">Distance</span><span class="pas-sym">;</span>
<span class="pas-space">    </span><span class="pas-ident">DistanceToNextVertex</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">PointDist</span><span class="pas-sym">(</span><span class="pas-ident">Canvas</span><span class="pas-sym">.</span><span class="pas-ident">PenPos</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">Vertices</span><span class="pas-sym">[</span><span class="pas-ident">Index</span><span class="pas-sym">]</span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-space">    </span><span class="pas-kwd">while</span><span class="pas-space"> </span><span class="pas-sym">(</span><span class="pas-ident">DistanceRemaining</span><span class="pas-space"> </span><span class="pas-sym">&gt;</span><span class="pas-space"> </span><span class="pas-ident">DistanceToNextVertex</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-kwd">do</span>
<span class="pas-space">    </span><span class="pas-kwd">begin</span>
<span class="pas-space">      </span><span class="pas-ident">DistanceRemaining</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">DistanceRemaining</span><span class="pas-space"> </span><span class="pas-sym">-</span><span class="pas-space"> </span><span class="pas-ident">DistanceToNextVertex</span><span class="pas-sym">;</span>
<span class="pas-space">      </span><span class="pas-ident">PlotTo</span><span class="pas-sym">(</span><span class="pas-ident">Vertices</span><span class="pas-sym">[</span><span class="pas-ident">Index</span><span class="pas-sym">]</span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-space">      </span><span class="pas-ident">Inc</span><span class="pas-sym">(</span><span class="pas-ident">Index</span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-space">      </span><span class="pas-kwd">if</span><span class="pas-space"> </span><span class="pas-sym">(</span><span class="pas-ident">Index</span><span class="pas-space"> </span><span class="pas-sym">&gt;</span><span class="pas-space"> </span><span class="pas-ident">High</span><span class="pas-sym">(</span><span class="pas-ident">Vertices</span><span class="pas-sym">)</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-kwd">then</span>
<span class="pas-space">        </span><span class="pas-ident">Exit</span><span class="pas-sym">;</span>
<span class="pas-space">      </span><span class="pas-ident">DistanceToNextVertex</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">PointDist</span><span class="pas-sym">(</span><span class="pas-ident">Canvas</span><span class="pas-sym">.</span><span class="pas-ident">PenPos</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">Vertices</span><span class="pas-sym">[</span><span class="pas-ident">Index</span><span class="pas-sym">]</span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-space">    </span><span class="pas-kwd">end</span><span class="pas-sym">;</span>
<span class="pas-space">    </span><span class="pas-kwd">with</span><span class="pas-space"> </span><span class="pas-ident">Canvas</span><span class="pas-sym">.</span><span class="pas-ident">PenPos</span><span class="pas-space"> </span><span class="pas-kwd">do</span>
<span class="pas-space">      </span><span class="pas-kwd">if</span><span class="pas-space"> </span><span class="pas-sym">(</span><span class="pas-ident">FltEqual</span><span class="pas-sym">(</span><span class="pas-ident">DistanceToNextVertex</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-num">0</span><span class="pas-sym">)</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-kwd">then</span>
<span class="pas-space">        </span><span class="pas-ident">PlotTo</span><span class="pas-sym">(</span><span class="pas-ident">Vertices</span><span class="pas-sym">[</span><span class="pas-ident">Index</span><span class="pas-sym">]</span><span class="pas-sym">)</span>
<span class="pas-space">      </span><span class="pas-kwd">else</span>
<span class="pas-space">        </span><span class="pas-ident">PlotTo</span><span class="pas-sym">(</span>
<span class="pas-space">          </span><span class="pas-ident">Point</span><span class="pas-sym">(</span>
<span class="pas-space">            </span><span class="pas-ident">Round</span><span class="pas-sym">(</span>
<span class="pas-space">              </span><span class="pas-ident">X</span><span class="pas-space"> </span><span class="pas-sym">+</span><span class="pas-space"> </span><span class="pas-ident">DistanceRemaining</span><span class="pas-space"> </span><span class="pas-sym">/</span><span class="pas-space"> </span><span class="pas-ident">DistanceToNextVertex</span>
<span class="pas-space">                </span><span class="pas-sym">*</span><span class="pas-space"> </span><span class="pas-sym">(</span><span class="pas-ident">Vertices</span><span class="pas-sym">[</span><span class="pas-ident">Index</span><span class="pas-sym">]</span><span class="pas-sym">.</span><span class="pas-ident">X</span><span class="pas-space"> </span><span class="pas-sym">-</span><span class="pas-space"> </span><span class="pas-ident">X</span><span class="pas-sym">)</span>
<span class="pas-space">            </span><span class="pas-sym">)</span><span class="pas-sym">,</span>
<span class="pas-space">            </span><span class="pas-ident">Round</span><span class="pas-sym">(</span>
<span class="pas-space">              </span><span class="pas-ident">Y</span><span class="pas-space"> </span><span class="pas-sym">+</span><span class="pas-space"> </span><span class="pas-ident">DistanceRemaining</span><span class="pas-space"> </span><span class="pas-sym">/</span><span class="pas-space"> </span><span class="pas-ident">DistanceToNextVertex</span>
<span class="pas-space">                </span><span class="pas-sym">*</span><span class="pas-space"> </span><span class="pas-sym">(</span><span class="pas-ident">Vertices</span><span class="pas-sym">[</span><span class="pas-ident">Index</span><span class="pas-sym">]</span><span class="pas-sym">.</span><span class="pas-ident">Y</span><span class="pas-space"> </span><span class="pas-sym">-</span><span class="pas-space"> </span><span class="pas-ident">Y</span><span class="pas-sym">)</span>
<span class="pas-space">            </span><span class="pas-sym">)</span>
<span class="pas-space">          </span><span class="pas-sym">)</span>
<span class="pas-space">        </span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-space">      </span><span class="pas-ident">Result</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">true</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-kwd">end</span><span class="pas-sym">;</span>

<span class="pas-kwd">var</span>
<span class="pas-space">  </span><span class="pas-ident">PatternIndex</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">Integer</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-ident">OldPenStyle</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">TPenStyle</span><span class="pas-sym">;</span>
<span class="pas-kwd">begin</span>
<span class="pas-space">  </span><span class="pas-ident">OldPenStyle</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">Canvas</span><span class="pas-sym">.</span><span class="pas-ident">Pen</span><span class="pas-sym">.</span><span class="pas-ident">Style</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-ident">Canvas</span><span class="pas-sym">.</span><span class="pas-ident">Pen</span><span class="pas-sym">.</span><span class="pas-ident">Style</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">psSolid</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-ident">Canvas</span><span class="pas-sym">.</span><span class="pas-ident">MoveTo</span><span class="pas-sym">(</span><span class="pas-ident">Vertices</span><span class="pas-sym">[</span><span class="pas-num">0</span><span class="pas-sym">]</span><span class="pas-sym">.</span><span class="pas-ident">X</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">Vertices</span><span class="pas-sym">[</span><span class="pas-num">0</span><span class="pas-sym">]</span><span class="pas-sym">.</span><span class="pas-ident">Y</span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-ident">PatternIndex</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-num">1</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-ident">Index</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-num">1</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-kwd">while</span><span class="pas-space"> </span><span class="pas-sym">(</span><span class="pas-ident">true</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-kwd">do</span>
<span class="pas-space">  </span><span class="pas-kwd">begin</span>
<span class="pas-space">    </span><span class="pas-ident">PenDown</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">true</span><span class="pas-sym">;</span>
<span class="pas-space">    </span><span class="pas-kwd">case</span><span class="pas-space"> </span><span class="pas-ident">Pattern</span><span class="pas-sym">[</span><span class="pas-ident">PatternIndex</span><span class="pas-sym">]</span><span class="pas-space"> </span><span class="pas-kwd">of</span>
<span class="pas-space">      </span><span class="pas-str">'.'</span><span class="pas-sym">:</span>
<span class="pas-space">        </span><span class="pas-kwd">if</span><span class="pas-space"> </span><span class="pas-kwd">not</span><span class="pas-sym">(</span><span class="pas-ident">Advance</span><span class="pas-sym">(</span><span class="pas-num">0</span><span class="pas-sym">)</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-kwd">then</span>
<span class="pas-space">          </span><span class="pas-ident">Break</span><span class="pas-sym">;</span>
<span class="pas-space">      </span><span class="pas-str">'-'</span><span class="pas-sym">:</span>
<span class="pas-space">        </span><span class="pas-kwd">if</span><span class="pas-space"> </span><span class="pas-kwd">not</span><span class="pas-sym">(</span><span class="pas-ident">Advance</span><span class="pas-sym">(</span><span class="pas-ident">DashLength</span><span class="pas-sym">)</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-kwd">then</span>
<span class="pas-space">          </span><span class="pas-ident">Break</span><span class="pas-sym">;</span>
<span class="pas-space">      </span><span class="pas-kwd">else</span>
<span class="pas-space">        </span><span class="pas-ident">ShowError</span><span class="pas-sym">(</span><span class="pas-str">''</span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-space">    </span><span class="pas-kwd">end</span><span class="pas-sym">;</span>
<span class="pas-space">    </span><span class="pas-ident">PenDown</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">false</span><span class="pas-sym">;</span>
<span class="pas-space">    </span><span class="pas-kwd">if</span><span class="pas-space"> </span><span class="pas-kwd">not</span><span class="pas-sym">(</span><span class="pas-ident">Advance</span><span class="pas-sym">(</span><span class="pas-ident">DashLength</span><span class="pas-sym">)</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-kwd">then</span>
<span class="pas-space">      </span><span class="pas-ident">Break</span><span class="pas-sym">;</span>
<span class="pas-space">    </span><span class="pas-ident">Inc</span><span class="pas-sym">(</span><span class="pas-ident">PatternIndex</span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-space">    </span><span class="pas-kwd">if</span><span class="pas-space"> </span><span class="pas-sym">(</span><span class="pas-ident">PatternIndex</span><span class="pas-space"> </span><span class="pas-sym">&gt;</span><span class="pas-space"> </span><span class="pas-ident">Length</span><span class="pas-sym">(</span><span class="pas-ident">Pattern</span><span class="pas-sym">)</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-kwd">then</span>
<span class="pas-space">      </span><span class="pas-ident">PatternIndex</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-num">1</span><span class="pas-sym">;</span>
<span class="pas-space">    </span><span class="pas-kwd">end</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-ident">Canvas</span><span class="pas-sym">.</span><span class="pas-ident">Pen</span><span class="pas-sym">.</span><span class="pas-ident">Style</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">OldPenStyle</span><span class="pas-sym">;</span>
<span class="pas-kwd">end</span><span class="pas-sym">;</span></pre>
</div>