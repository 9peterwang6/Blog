Effective Data Visualization, or How Not to Lie with Charts
-----------------------------------------------------------

### What is data visualization?

Simple, visualize data. Or use charts to present data.

### Why do we need data visualization?

There are two reasons why we need data visualization:

*   Exploratory: to explore the data and find out if there are any interesting patterns in your data.
*   Explanatory: to present the patterns that you find out to people who don't know about it.

### OK, so how to do it?

There are a few steps to visualize your data:

<ul>
    <li>
        Format your data. Data may come in many formats, but for most data visualization softwares we use, they only recognize "tidy" data. Tidy data means that each variable you observe forms a column and each observation forms a row. Following is a very interesting example of tidy data and how you can tidy your data.<br><br>
        <img src="../pictures/UCR-DataVisualizationWorkshop-1.png" width="50%"><br><br>
        You can use the following tools to help you transform/pivot/tidy your data: Datawrapper, Tableau Public, OpenRefine.
    </li>
    <li>Figure out what you want to do with the data. If you need to quickly reproduce lots of simple charts to explore data, then you should try a programming solution like R or python. If you want to create interactive charts or infographics to present the patterns you have found, then you can try Plotly, Datawrapper, or Tableau Public.</li>
    <li>Figure out what chart type you want to use. If you are not sure about which chart type to use, you can use the flowchart on <a href="https://www.data-to-viz.com/" target="_blank">From Data to Viz</a> or checkout <a href="https://datavizproject.com/" target="_blank">The Data Viz Project</a>. If you prefer using a JavaScript library to create the chart, you can check out <a href="https://datavizcatalogue.com/" target="_blank">Data Viz Catalog</a> to find out which libraries or tools are recommended.</li>
    <li>Choose a data visualization tool. You can use this research guide from <a href="https://research.lib.buffalo.edu/dataviz/tools" target="_blank">University at Buffalo</a> to see which tools are free and which tools require proprietary license. Some free-to-use browser-based tools include: Datawrapper, Plotly Chart Studio, Google Charts, RAWGraphs, and Data Illustrator. If you want to go with a programming environment, you can use ggplot2, lattice in R, matplotlib, bokeh in python and d3.js in JavaScript. You can also use Tableau Public if you want to install a desktop software. Brower-based tools can let you create simple charts very easily and quickly whereas advanced statistical softwares (e.g. Stata, SAS, Matlab) or programming environment are most suitable for complex charts or a series of visually consistent graphs. If you want static charts, you can use Excel, Datawrapper and some R ror python libraries. If you want to use interactive online charts, you can try Tableau Public, Plotly, Google Charts, or R + shiny web apps.</li>
</ul>

Some useful resources if you want to learn more about data visualization:

*   Andy Kirk's [Visualising Data](http://www.visualisingdata.com/blog/) blog and book, [Data Visualization (2012)](https://ucr.primo.exlibrisgroup.com/permalink/01CDL_RIV_INST/18blg5g/alma991033538396604706)
*   Cole Nussbaumer Knaflic's [Storytelling with Data](http://www.storytellingwithdata.com/) blog and book, [Storytelling with Data (2015)](https://ucr.primo.exlibrisgroup.com/permalink/01CDL_RIV_INST/1jkon0k/alma991032958127804706)
*   [Flowing Data](https://flowingdata.com/), Nathan Yau's blog
*   [EagerEyes](https://eagereyes.org/), Robert Kosara's blog
*   [Chartable](https://blog.datawrapper.de/), the Datawrapper blog

### Now you know about the basics of data visualization, and you probably have seen many charts on many things around the world. But since data can lie, visualizations based on those data can also lie. Here is what we can do to lie via data visualization and how not to do it.

#### Optical Illusion

Our brains are better at judging lengths than judging angles and areas. So if you want to emphasize something that does not have a significant difference than others, you can use a pie chart. But if you want to use a pie chart and avoid such issue, you need to pay attention to the following:

*   Make sure your data adds up to 100%
*   Use as few slices as possible
*   Directly label the slices
*   Sort the slices large to small, ideally starting at 12 o'clock.

Another chart you can use to skew your audience is to use radial bar charts. Because the the bars will form an arc with the same central point, the bars that are farther away from the central point will have a longer arc even though their value are not larger than the bars that are closer to the central point. If you want to avoid such issue, simply use a bar chart.

Three-dimensional charts can make elements in the front of the chart look larger and elements at the back look smaller. This is because different parts of the graph form different angles with our eyes and these angles can skew the area or length if they are not right angles. Avoid using 3D charts when visualization data.

#### Mental Arithmetic

Our brain is not good at multitasking, so if you ask your readers to do mental calculations in order to understand the data, you can actually mislead or confuse them with your charts.

One example is charts with dual axes. The two scales are arbitrary and can mislead readers about the relationahip (especially the differences in numbers) between the two data series. To avoid this problem one use two separate charts with their own axes.

Stacking your charts toghether may make it difficult for readers to identify specific data and readers have to do mental computations to intepret data. One example is the use of stacked area charts. The problem with this type of charts is that some areas will be covered by others so readers can't find out the exact values easily. So it is better to use separate charts or use line charts instead.

Another example is the use of stacked bar charts. This type of chart makes it very difficult to compare the diferent bar heights. So it is better to separate the bar charts inestead of stacking them.

#### Subverting Expectations

It is a very interesting name. But this basically means not using the presentations that we normally see.

For example, in order to magnify the differences, one can cut the X axis (i.e. use an X axis that does not begin with 0) of a horizontal barchart. When we put back the missing portion the differences become not that significant when we cut the axis. There is one exxception though. That is cuttting the Y axis in line charts. This does not distort the perception. But readers may still expect that the Y axis begins from 0 at first glance. So it is better to let the Y axis begin from 0 but use a symbol that tells readers that you skipped some of the values if you can or at least point out that the Y axis in the chart does not begin from 0.

One can also reverse the axis of the graph (e.g. let the Y axis begin from the top instead from the bottom) or invert a color scale (use dark colors to mean low values and light colors to mean high values instead of the opposite) to make thing confusing. This is basically due to the fact that we have seen so many charts that use a somewhat conventional format. This makes us not feeling comfortable when seeing something not following the conventional format.

#### Incorrect Colors

Not appropriate colors can make things misleading. One example is using rainbow colors on sequential/numeric data instead of categorical data.

Color should map to a variable or used to call attention to specific data. In the other cases you don't need to use different colors for your data.

#### Incorrect Scaling of Chart Elements

This can happen in many cases. One case is scaling circles by radius intead of area. Scaling by radius will grow the area quadratically, this could distort the data to make a small difference feel large. To mitigate the problem one can scale by the square root of the radius. An alternative is to scale the circles by circumfence instead.

Another case is the scale of the axes you use. When you have large discrepancies of values (i.e. Some values are more than 100x larger than other data) on a single axis, using a linear scale can erase some of your data. You should use a log scale for your axes in this case. In the other cases linear works better.